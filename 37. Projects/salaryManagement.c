/***It's a code to salary management of employee***/
/***Algorithm: Basic file handling algorithm is used here***/

//@Author: Soumyadip Ghosh (Github: https://github.com/SoumyadipGhosh23)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int list();
int TotalAmount, Totalcredit, Totaldebit;

void credit(void);

void last(void);

void checkdetail(void);

void withdraw(void);

int Amount, Amo, tr;

int pin;

char a[100];

int main()

{
    TotalAmount = 1000;
    Totalcredit = 0;
    Totaldebit = 0;

    int choice;

    int x, pinCount=0;

    printf("\nEnter your name: ");
    scanf("%[^\n]%*c", a);

    flag2:
    while(pinCount != 2){
        printf("\nEnter Your Pin: ");
        scanf("%d", &pin);
        pinCount++;
        if(pin != 6996 && pinCount != 2){
            printf("\nIncorrect Pin, Try Again.......");
            getch();
            goto flag2;
        }
        else if(pin != 6996 && pinCount ==2){
            printf("\nYou've entered wrong pin multiple times!!!!!");
            exit(0);
        }
        else if(pin == 6996){
            break;
        }
    }

flag:

    x = list();

    switch (x)

    {

    case 1:

        credit();

        break;

    case 2:

        withdraw();

        break;

    case 3:

        checkdetail();

        break;

    default:

        printf("\nInvalid choice: ");
    }

    printf("\nDo you want to continue(1 for Yes/0 for No): ");
    getchar();

    scanf("%d", &choice);

    if (choice == 1)

    {
        goto flag;
    }

    else
    {
        last();
    }

    return 0;
}

int list()

{

    int ch;

    printf("\n1. Credit Amount: ");

    printf("\n2. Debit Amount: ");

    printf("\n3. Check Details: ");

    printf("\n4. EXIT");

    printf("\nEnter your choice: ");

    scanf("%d", &ch);

    return ch;
}

void credit()

{
    FILE *fp;
    fp = fopen("transaction.txt", "a");

    printf("\nEnter the Credit Amount: ");

    scanf("%d", &Amount);

    TotalAmount += Amount;

    Totalcredit += Amount;

    fprintf(fp, "%d %d %d ", TotalAmount, Totalcredit, Totaldebit);

    printf("Amount Credited Successful\n");
    fclose(fp);
}

void withdraw()

{
    FILE *fp;
    fp = fopen("transaction.txt", "a");

    printf("\nEnter the Debit Amount: ");

    scanf("%d", &Amo);

    if (Amo <= TotalAmount)

    {

        TotalAmount -= Amo;

        Totaldebit += Amo;

        printf("Amount Debited successfully\n");
    }

    else

    {
        printf("\nWithdraw is not possible, Please try again : ");
    }
    fprintf(fp, "%d %d %d ", TotalAmount, Totalcredit, Totaldebit);
    fclose(fp);
}

void checkdetail()

{
    FILE *fp;
    fp = fopen("transaction.txt", "r");

    printf("\nTotal Amount\tTotal Credited Amount\tTotal Debited Amount\n");
    while (fscanf(fp, "%d  %d  %d", &TotalAmount, &Totalcredit, &Totaldebit) != EOF)
    {
        printf("%d                  %d                    %d\n", TotalAmount, Totalcredit, Totaldebit);
    }
    fclose(fp);
}

void last()

{
    FILE *fp;
    fp = fopen("transaction.txt", "r");

    printf("\nYour name: %s", a);

    printf("\nTotal Amount\tTotal Credited Amount\tTotal Debited Amount\n");
    while (fscanf(fp, "%d  %d  %d", &TotalAmount, &Totalcredit, &Totaldebit) != EOF)
    {
        printf("  %d                %d                    %d\n", TotalAmount, Totalcredit, Totaldebit);
    }

    printf("\n\n\t\t\t***THANK YOU***");
}
