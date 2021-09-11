#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int coff;
	int exp;
	struct node *link;
} poly;
poly *create()
{
	poly *temp = (poly *)malloc(sizeof(poly));
	return temp;
}
poly *insert_poly(poly *start)
{
	poly *dstart = start;
	int coff;
	int exp;
	printf("enter the coffecient and the expo:\n");
	scanf("%d", &coff);
	scanf("%d", &exp);
	poly *temp = create();
	temp->exp = exp;
	temp->coff = coff;
	temp->link = NULL;
	if (start == NULL)
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
int compare(int exp1, int exp2)
{
	if (exp1 > exp2)
		return 1;
	else if (exp1 < exp2)
		return 2;
	else
		return 3;
}
poly *insert(poly *temp, poly *start)
{
	poly *dstart = start;
	if (start == NULL)
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
void polynomial(poly *start1, poly *start2, poly *start3)
{
	poly *temp;
	int c;
	poly *dstart1 = start1;
	poly *dstart2 = start2;
	poly *dstart3 = start3;
	while (dstart1 != NULL && dstart2 != NULL)
	{
		switch (compare(dstart1->exp, dstart2->exp))
		{
		case 1:
			temp = create();
			temp->coff = dstart1->coff;
			temp->exp = dstart1->exp;
			start3 = insert(temp, start3);
			dstart1 = dstart1->link;
			break;
		case 2:
			temp = create();
			temp->coff = dstart2->coff;
			temp->exp = dstart2->exp;
			start3 = insert(temp, start3);
			dstart2 = dstart2->link;
			break;
		case 3:
			c = dstart1->coff + dstart2->coff;
			if (c != 0)
			{
				temp = create();
				temp->coff = c;
				temp->exp = dstart2->exp;
				start3 = insert(temp, start3);
			}
			dstart1 = dstart1->link;
			dstart2 = dstart2->link;
			break;
		}
	}
	if (dstart1 != NULL)
	{
		while (dstart1 != NULL)
		{
			temp = create();
			temp->coff = dstart1->coff;
			temp->exp = dstart1->exp;
			start3 = insert(temp, start3);
			dstart1 = dstart1->link;
		}
	}
	else
	{
		while (dstart2 != NULL)
		{
			temp = create();
			temp->coff = dstart2->coff;
			temp->exp = dstart2->exp;
			start3 = insert(temp, start3);
			dstart2 = dstart2->link;
		}
	}
}
void display(poly *start)
{
	while (start != NULL)
	{
		printf("%d  %d\n", start->coff, start->exp);
		start = start->link;
	}
}
int main()
{
	int n;
	poly *start1 = NULL;
	poly *start2 = NULL;
	poly *start3 = NULL;
	printf("Please enter the coff and exp of polynomial 1:\n");
	printf("Please enter the number of terms\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		start1 = insert_poly(start1);
	}
	printf("Please enter the coff and exp of polynomial 2:\n");
	printf("Please enter the number of terms\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		start2 = insert_poly(start2);
	}
	polynomial(start1, start2, start3);
	display(start1);
	display(start2);
	display(start3);
}
