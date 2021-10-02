#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct library {
	char book_name[20];
	char author[20];
	int pages;
	float price;
};
int main()
{
	struct library lib[100];
	char ar_nm[30], bk_nm[30];
	int i, input, count;
	i = input = count = 0;
	while (input != 5) {
		printf("\n\n1. Add book infor"
			"mation\n2. Display "
			"book information\n");
		printf("3. List all books of "
			"given author\n");
		printf(
			"4. List the count of book"
			"s in the library\n");
		printf("5. Exit");
		printf("\n\nEnter one of "
			"the above: ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("Enter book name = ");
			scanf("%s", lib[i].book_name);
			printf("Enter author name = ");
			scanf("%s", lib[i].author);
			printf("Enter pages = ");
			scanf("%d", &lib[i].pages);
			printf("Enter price = ");
			scanf("%f", &lib[i].price);
			count++;
			break;
		case 2:
			printf("you have entered"
				" the following "
				"information\n");
			for (i = 0; i < count; i++) 
            {
				printf("book name = %s",
					lib[i].book_name);
				printf("\t author name = %s",
					lib[i].author);
				printf("\t pages = %d",
					lib[i].pages);
				printf("\t price = %f",
					lib[i].price);
			}
			break;
		case 3:
			printf("Enter author name : ");
			scanf("%s", ar_nm);
			for (i = 0; i < count; i++) 
            {
				if (strcmp(ar_nm,
						lib[i].author)
					== 0)
					printf("%s %s %d %f",
						lib[i].book_name,
						lib[i].author,
						lib[i].pages,
						lib[i].price);
			}
			break;
		case 4:
			printf("\n No of books in "
				"brary : %d",
				count);
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}