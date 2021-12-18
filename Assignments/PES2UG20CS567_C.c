#include <stdio.h>
#include <stdlib.h>
#include "PES2UG20CS567_H.h"
void main()
{
	list_t* head=(list_t*)malloc(sizeof(list_t));
	head=NULL;
	int* coordinate=read_map(&head);
	find_path(coordinate,head);
}