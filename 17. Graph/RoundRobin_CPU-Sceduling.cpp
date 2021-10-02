


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<iostream.h>

#include <malloc.h>


struct node
{
	int arrival;
	int burst;
	int burst1;
	int turnaround;
	int waiting;
	int finish;
	int name;

	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;


int empty()
{
	if (tail == NULL)
		return 1;
	else
		return 0;
}

void append (struct node *temp)
{			
	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail -> next = temp;
		tail = temp;
		tail -> next = NULL;
	}
}

struct node* serve ()
{
	struct node *temp;
			
	if (!empty())
	{
		temp = head;
		head = head -> next;

		return temp;			
	}
	else
	{
		temp = new(node);
		temp -> arrival = 0;
		temp -> burst = 0;
		temp -> burst1 = 0;
		temp -> turnaround = 0;
		temp -> waiting = 0;
		temp -> finish = 0;
		temp -> name = 0;

		return temp;
	}
}	

int main()
{
	int max = 10;

	struct node *p[10];
	struct node *exe;

	int quantum = 2;
	int period = 0;
	int count = 0;
	int i;
	int choice;

	double totalWaiting = 0;
	double avgWaiting;

	cout<<"******** Please select your choice ********"<<endl<<endl;
	cout<<"1.Processes with same arrival time 0"<<endl<<endl;
	cout<<"2.Processes with random arrival time"<<endl<<endl;

	cout<<"Your option is (1 / 2) >> "<<endl;
	cin>>choice; 
	if (choice != 1 && choice != 2)
	{cout<<"Invalid option";	}	
	else
	{ for (i = 0; i < max; i++)
		{	p[i] =new(node);
			p[i] -> turnaround = 0;
			p[i] -> waiting = 0;
			p[i] -> finish = 0;
			p[i] -> name = i + 1;
			p[i] -> next = NULL;
		}

		if (choice == 1)
		{
			for (i = 0; i < max; i++)
			{
				p[i] -> arrival = 0;
			}
		}

		if (choice == 2)
		{
			p[0] -> arrival = 0;

			for (i = 1; i < max; i++)
			{
				p[i] -> arrival = (rand() % 10) * 2;
			}
		}

		for (i = 0; i < max; i++)
		{
			cout<<"Enter burst time for Process >> "<<i + 1<<endl;
			cin>>p[i] -> burst; 
			p[i] -> burst1 = p[i] -> burst;
		}

		printf("\n\n");

		printf("TimeB\t\tTimeE\t\tProcess\t\tArrival\t\tBurst\t\t\n\n");

		getch();

		if (choice == 1)
		{
			for (i = 0; i < max; i++)
			{
				if (p[i] -> arrival == period)
				{
					append (p[i]);
				}
			}
		}
		
		while (period < 100 && count < max)
		{
			if (choice == 2)
			{
				for (i = 0; i < max; i++)
				{
					if (p[i] -> arrival == period)
					{
						append (p[i]);
					}
				}
			}

			exe = new(node);
			exe = serve();

			if (exe -> name != 0)
			{
				if (exe -> burst1 > quantum)
				{
					printf ("%d\t\t", period); 
					exe -> burst1 = exe -> burst1 - quantum;
					period = period + quantum;

					printf ("%d\t\t%d\t\t%d\t\t%d\tQ\n", period, exe -> name, exe -> arrival, exe -> burst1);

					if (exe -> burst1 == 0)
					{
						period = period + exe -> burst1;
						exe -> burst1 = 0;
						exe -> finish = period;
						exe -> turnaround = exe -> finish - exe -> arrival;
						exe -> waiting = exe -> turnaround - exe -> burst;

						count ++;

						for (i = 0; i < max; i++)
						{
							if (p[i] -> name == exe -> name)
							{
								p[i] = exe;
							}
						}

	printf ("%d\t\t%d\t\t%d\t\t%d\tFinish\n", period, exe -> name, exe -> arrival, exe -> burst1);
							
					}					
					else
						append (exe); 
							
					getch();
				} 
				else
				{
					if (exe -> burst1 != 0)
					{
						cout<< period<<"   ";
						period = period + exe -> burst1;
						exe -> burst1 = 0;
						exe -> finish = period;
						exe -> turnaround = exe -> finish - exe -> arrival;
						exe -> waiting = exe -> turnaround - exe -> burst;

						count ++;

						for (i = 0; i < max; i++)
						{
							if (p[i] -> name == exe -> name)
							{
								p[i] = exe;
							}
						}


printf ("%d\t\t%d\t\t%d\t\t%d\tFinish\n", period, exe -> name, exe -> arrival, exe -> burst1);						
						
						getch();
					}
				}
			} 
			else
			{
				if (count < max)
				{
						printf ("%d\t\t", period);
				}					

				period = period + quantum;

				if (count < max)
				{
						printf ("%d", period);
				}					
			}		
		} 

		cout<<endl<<endl<<endl;

		printf("Process\t\tFinish time\t\tTurnAround time\t\tWaiting time\t\t\n");

		for (i = 0; i < max; i++)
		{
			printf ("%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i] -> name, p[i] -> finish, p[i] -> turnaround, p[i] -> waiting);	
		}			
		for (i = 0; i < max; i++)
		{totalWaiting = totalWaiting + p[i] -> waiting;
		}
		avgWaiting = totalWaiting / max;
		cout<<endl<<endl;
		cout<<"Average waiting time is  "<<avgWaiting<<endl;
		getch();
	} 
} 

