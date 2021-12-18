#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
	int data;
	struct node *link;
} sll;

sll *create();
sll *del_alt(sll *start);
sll *insert_start(int ele, sll *start);
sll *insert_end(int ele, sll *start);
sll *insert_pos(int ele, sll *start, int pos);
sll *del_start(sll *start);
sll *del_end(sll *start);
sll *del_pos(sll *start, int pos);
sll *swap(sll *start, int pos1, int pos2);
void display(sll *start);
void merge();
void concat();
void main()
{
	int ele, pos, pos2;
	int num;
	struct node *start = NULL;
	printf("%d", start);
	fflush(stdin);
	while (1 != 0)
	{
		system("cls");
		printf("Please select the option from the menu:\n");
		printf("1.INSERT AT START\n2.INSERT AT END\n3.INSERT AT A GIVEN POS\n4.DELET AT START\n5.DELET AT END\n6.DELET AT A GIVEN POSITION\n7.DISPLAY\n8.CONCATINTE\n9.MERGE\n10.SWAP\n11.DELET ALTERNATIVE\n12.EXIT\n");
		fflush(stdin);
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			scanf("%d", &ele);
			start = insert_start(ele, start);
			getch();
			break;
		case 2:
			scanf("%d", &ele);
			start = insert_end(ele, start);
			getch();
			break;
		case 3:
			scanf("%d", &ele);
			printf("ENTER THE POSITION: \n");
			scanf("%d", &pos);
			start = insert_pos(ele, start, pos);
			getch();
			break;
		case 4:
			start = del_start(start);
			getch();
			break;
		case 5:
			start = del_end(start);
			getch();
			break;
		case 6:
			printf("ENTER THE POSITION: \n");
			scanf("%d", &pos);
			start = del_pos(start, pos);
			getch();
			break;
		case 7:
			display(start);
			getch();
			break;
		case 8:
			concat();
			break;
		case 9:
			merge();
			getch();
			break;
		case 10:
			printf("ENTER THE POSITION 1: \n");
			scanf("%d", &pos);
			printf("ENTER THE POSITION 2: \n");
			scanf("%d", &pos2);
			start = swap(start, pos, pos2);
			break;
		case 11:
			start = del_alt(start);
			break;
		case 12:
			exit(0);
		}
	}
}

sll *create()
{
	sll *temp = (struct node *)malloc(sizeof(struct node));
	return temp;
}
sll *insert_start(int ele, sll *start)
{
	sll *temp = create();
	temp->data = ele;
	temp->link = NULL;
	if (start != NULL)
	{
		temp->link = start;
	}
	start = temp;
	return start;
}
sll *insert_end(int ele, sll *start)
{
	sll *dstart = start;
	sll *temp = create();
	temp->data = ele;
	temp->link = NULL;
	if (dstart == NULL)
		start = temp;
	else
	{
		while (dstart->link != NULL)
		{
			dstart = dstart->link;
		}
		dstart->link = temp;
	}
	return start;
}
sll *insert_pos(int ele, sll *start, int pos)
{
	int i = 1;
	sll *dstart = start;
	sll *temp = create();
	temp->data = ele;
	temp->link = NULL;
	if (dstart == NULL)
	{
		start = temp;
	}
	else
	{
		while (dstart != NULL && i < pos - 1)
		{
			dstart = dstart->link;
			i++;
		}
		if (dstart != NULL && i <= pos - 1)
		{
			temp->link = dstart->link;
			dstart->link = temp;
		}
		else if (dstart == NULL)
		{
			printf("out of range\n");
		}
	}
	return start;
}
sll *del_start(sll *start)
{
	sll *dstart = start;
	if (dstart = NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		start = start->link;
		free(dstart);
		dstart = NULL;
	}
	return start;
}
sll *del_end(sll *start)
{
	sll *dstart = start;
	if (dstart == NULL)
	{
		printf("List is empty\n");
	}
	else if (dstart->link == NULL)
	{
		free(start);
		start = NULL;
	}
	else
	{
		while (dstart->link->link != NULL)
		{
			dstart = dstart->link;
		}
		free(dstart->link);
		dstart->link = NULL;
	}
	return start;
}
sll *del_pos(sll *start, int pos)
{
	int i = 0;
	sll *temp;
	sll *dstart = start;
	if (dstart == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		if (pos == 1)
		{
			start = dstart->link;
			free(dstart);
			dstart = NULL;
		}
		else
		{
			while (i < pos - 2 && dstart != NULL)
			{
				dstart = dstart->link;
			}
			temp = dstart->link;
			dstart->link = dstart->link->link;
			free(temp);
			temp = NULL;
		}
	}
	return start;
}
void display(sll *start)
{
	while (start != NULL)
	{
		printf("%d\t", start->data);
		start = start->link;
	}
}
void concat()
{
	int num = 0;
	sll *list1 = NULL;
	sll *list2 = NULL;
	int n = 0;
	printf("PLEASE ENTER THE NUMBER OF ELEMENTS U WANT:\n");
	scanf("%d", &n);
	printf("PLEASE ENTER THE ELEMENTS FOR THE FIRST LIST(enter N to stop):\n");
	for (int i = 0; i < n; i++)
	{
		printf("Please enter the data\n");
		scanf("%d", &num);
		list1 = insert_end(num, list1);
	}
	printf("PLEASE ENTER THE NUMBER OF ELEMENTS U WANT:\n");
	scanf("%d", &n);
	printf("PLEASE ENTER THE ELEMENTS FOR THE SECOND LIST(enter N to stop):\n");
	for (int i = 0; i < n; i++)
	{
		printf("Please enter the data\n");
		scanf("%d", &num);
		list2 = insert_end(num, list2);
	}
	sll *dstart = list1;
	while (dstart->link != NULL)
	{
		dstart = dstart->link;
	}
	dstart->link = list2;
	display(list1);
	getch();
}
void merge()
{
	int num = 0;
	sll *list1 = NULL;
	sll *list2 = NULL;
	sll *list3 = NULL;
	int n = 0;
	printf("PLEASE ENTER THE NUMBER OF ELEMENTS U WANT:\n");
	scanf("%d", &n);
	printf("PLEASE ENTER THE ELEMENTS FOR THE FIRST LIST(enter N to stop):\n");
	for (int i = 0; i < n; i++)
	{
		printf("Please enter the data\n");
		scanf("%d", &num);
		list1 = insert_end(num, list1);
	}
	printf("PLEASE ENTER THE NUMBER OF ELEMENTS U WANT:\n");
	scanf("%d", &n);
	printf("PLEASE ENTER THE ELEMENTS FOR THE SECOND LIST(enter N to stop):\n");
	for (int i = 0; i < n; i++)
	{
		printf("Please enter the data\n");
		scanf("%d", &num);
		list2 = insert_end(num, list2);
	}
	sll *dstart = list1;
	while (dstart->link != NULL)
	{
		dstart = dstart->link;
	}
	dstart->link = list2;
	dstart = list1;
	while (dstart != NULL)
	{
		list3 = insert_end(dstart->data, list3);
		dstart = dstart->link;
	}
	display(list3);
}
sll *swap(sll *start, int pos1, int pos2)
{
	int i = 0;
	sll *pr1 = start;
	sll *pr2 = start;
	sll *pa1 = NULL;
	sll *pa2 = NULL;
	sll *temp = NULL;
	if (start->link->link == NULL)
	{
		pr1->link = NULL;
		start->link->link = start;
		start = pr2->link;
	}
	else if (pos1 == 1)
	{
		while (pr2->link != NULL && i < pos2 - 1)
		{
			pa2 = pr2;
			pr2 = pr2->link;
			i++;
		}
		if (pr2->link == NULL && i > pos2 - 1)
			printf("OUT OF RANGE\n");
		else
		{
			if (pos2 - pos1 == 1)
			{
				pr1->link = pr2->link;
				pr2->link = pr1;
				start = pr2;
			}
			else
			{
				temp = pr1->link;
				pr1->link = pr2->link;
				pr2->link = temp;
				pa2->link = pr1;
				start = pr2;
			}
		}
	}
	else
	{
		while (pr1->link != NULL && i < pos1 - 1)
		{
			pa1 = pr1;
			pr1 = pr1->link;
			i++;
		}
		i = 0;
		while (pr2->link != NULL && i < pos2 - 1)
		{
			pa2 = pr2;
			pr2 = pr2->link;
			i++;
		}
		if (pr2->link == NULL && i > pos2 - 1)
			printf("OUT OF RANGE\n");
		else
		{
			if (pos2 - pos1 == 1)
			{
				pr1->link = pr2->link;
				pr2->link = pr1;
				pa1->link = pr2;
			}
			else
			{
				temp = pr1->link;
				pr1->link = pr2->link;
				pr2->link = temp;
				pa1->link = pr2;
				pa2->link = pr1;
			}
		}
	}
	return start;
}
sll *del_alt(sll *start)
{
	int i = 0;
	sll *temp = NULL;
	sll *dstart = start;
	while (dstart != NULL)
	{
		if (dstart->link == NULL)
		{
			dstart = dstart->link;
		}
		else
		{
			if (i == 0)
			{
				temp = dstart;
				start = dstart->link;
				dstart = dstart->link;
				free(temp);
				temp = NULL;
			}
			else
			{
				temp = dstart->link;
				dstart->link = temp->link;
				dstart = dstart->link;
				free(temp);
				temp = NULL;
			}
		}
		i++;
	}
	return start;
}