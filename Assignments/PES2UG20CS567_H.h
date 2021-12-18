#ifndef MULTIL_H
#define MULTIL_H
struct list
{
	int x;
	int y;
	int count;
	struct list *down;
	struct list *right;
};
typedef struct list list_t;

struct queue
{
	struct list *node;
	struct queue *next;
};
typedef struct queue queue_t;

int* read_map(list_t** head_main);
void link(list_t **head1,list_t **head2);
list_t* new_node(int x, int y);
list_t* create_list(char line[100],int i,int len);
char* no_space(char str[100],int len);
list_t* enqueue(list_t* head, int x,int y);
void find_path(int *c, list_t *head);
queue_t* enqueue_path(queue_t *head,list_t* node);
list_t * pop(queue_t **head);
list_t* dequeue_path(queue_t **head);
#endif