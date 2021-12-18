#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PES2UG20CS567_H.h"
// head_t* read_map(head_t* head_main)
int *read_map(list_t **head_main) // double pointer
{

	int coordinates[4];
	FILE *f = fopen("input.txt", "r");
	char line[100];
	list_t *ptr_array[11];
	//*ptr_array = (int*)malloc(sizeof(int*)*10);
	// printf("2");
	fgets(line, sizeof(line), f);
	coordinates[0] = line[0] - 48;
	coordinates[1] = line[2] - 48;
	fgets(line, sizeof(line), f);
	coordinates[2] = line[0] - 48;
	coordinates[3] = line[2] - 48;
	// printf("in");
	int i = 0;
	int len;
	while (fgets(line, 100, f) != NULL)
	{
		// printf("in");
		len = strlen(line);
		int m, n;
		for (m = 0; m < len; m++) // for removing white spaces
		{
			if (line[m] == ' ' || line[m] == '\n')
			{
				for (n = m; n < len; n++)
				{
					line[n] = line[n + 1];
				}
				--len;
			}
		}
		// printf("out");
		// printf("%s \n",line);
		ptr_array[i] = create_list(line, i, len);
		//	printf("The line: %s",line);//test
		i++;
	}
	int j;
	for (j = 0; j < i; j++)
	{
		link(&ptr_array[j], &ptr_array[j + 1]);
	}
	*head_main = ptr_array[0];
	fclose(f);
	int *n = coordinates;
	list_t *temp = (list_t *)malloc(sizeof(list_t));
	temp = ptr_array[9];
	/*while(temp!=NULL)
	{
		printf("%d %d",temp->x,temp->y);
		printf("  %p\n",temp->right);
		temp=temp->right;
	}*/
	return n;
}

void link(list_t **head1, list_t **head2)
{
	list_t *temp1 = *head1;
	list_t *temp2 = *head2;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->y == temp2->y)
		{
			temp1->down = temp2;
			temp1 = temp1->right;
			temp2 = temp2->right;
		}
		else if (temp1->y > temp2->y)
		{
			temp2 = temp2->right;
		}
		else
		{
			temp1 = temp1->right;
		}
	}
}
list_t *new_node(int x, int y)
{
	list_t *temp = (list_t *)malloc(sizeof(list_t));
	temp->x = x;
	temp->y = y;
	temp->count = 0;
	temp->right = NULL;
	temp->down = NULL;
	return temp;
}

list_t *enqueue(list_t *head, int x, int y)
{
	if (head == NULL)
	{
		head = new_node(x, y);
		// printf("%d",head->x);
		return head;
		// return new_node(x,y);
	}
	else
	{
		list_t *temp = (list_t *)malloc(sizeof(list_t));
		temp = head;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		temp->right = new_node(x, y);
		return head;
	}
}

list_t *create_list(char line[100], int i, int len)
{
	list_t *head = (list_t *)malloc(sizeof(list_t));
	head = NULL;
	int j = 0;
	// printf("length : %d\n",len);
	while (j < len)
	{
		/*if(i==9)
		{
			printf("len : %d ",len);
			printf("j : %d\n ",j);
			printf("line : %c\n",line[9]);
		}*/
		if (line[j] == '0')
		{
			head = enqueue(head, i, j);
			// printf("head enqueued\n");
			// printf("%d\t", head->x);
			// printf("%d\n", head->y);
		}
		j++;
	}
	return head;
}

queue_t *enqueue_path(queue_t *head, list_t *node)
{
	queue_t *temp = (queue_t *)malloc(sizeof(queue_t));
	temp;
	// printf("%d",);
	if (head == NULL)
	{
		// printf("in");//printing
		// printf("\n%d",node->x);//printing
		temp->node = node;
		// printf("%d",temp->node->x);//not printng
		temp->next = NULL;
		// printf("%d",temp->node->x);
		head = temp;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		queue_t *temp1 = (queue_t *)malloc(sizeof(queue_t));
		temp1->node = node;
		temp1->next = NULL;
		temp->next = temp1;
	}
	return head;
}

list_t *pop(queue_t **head)
{
	queue_t *pres = (queue_t *)malloc(sizeof(queue_t));
	queue_t *prev = (queue_t *)malloc(sizeof(queue_t));
	pres = *head;
	prev = NULL;
	if (pres == NULL)
	{
		return NULL;
	}
	else
	{
		while (pres->next != NULL)
		{
			prev = pres;
			pres = pres->next;
		}
		prev->next = NULL;
		return pres->node;
	}
}

list_t *dequeue_path(queue_t **head)
{
	queue_t *temp = (queue_t *)malloc(sizeof(queue_t));
	temp = *head;
	(*head) = (*head)->next;
	return temp->node;
}

void find_path(int *c, list_t *head)
{
	int x = 0;
	int start_x = *c;
	int start_y = *(c + 1);
	int end_x = *(c + 2);
	int end_y = *(c + 3);
	list_t *temp = (list_t *)malloc(sizeof(list_t));
	temp = head;
	queue_t *front = (queue_t *)malloc(sizeof(queue_t));
	front = NULL;
	while (temp->x != end_x || temp->y != end_y)
	{
		// printf("%d %d\n",temp->x,temp->y);
		if (temp->right != NULL && (temp->y - temp->right->y) == -1 && temp->count == 0)
		{
			temp->count += 1;
			front = enqueue_path(front, temp);
			temp = temp->right;
		}
		else if (temp->count == 2)
		{
			x = 1;
			break;
		}
		else
		{
			if (temp->count == 1 && (temp->right == NULL || (temp->y - temp->right->y) != -1))
			{
				temp = pop(&front);
			}
			else if (temp->right == NULL && temp->down == NULL)
			{
				temp = pop(&front);
			}
			else
			{
				temp->count += 1;
				front = enqueue_path(front, temp);
				temp = temp->down;
			}
		}
	}
	FILE *f = fopen("output.txt", "w+");
	if (x == 1)
	{
		printf("No possible path found");
		fputs("No possible path found", f);
		fclose(f);
	}
	else
	{
		printf("\nPath: \n");
		front = enqueue_path(front, temp);
		while (front != NULL)
		{
			list_t *values = (list_t *)malloc(sizeof(list_t));
			values = dequeue_path(&front);
			printf("%d %d\n", values->x, values->y);
			fprintf(f, "%d %d\n", values->x, values->y);
			free(values);
		}
	}
	fclose(f);
}
