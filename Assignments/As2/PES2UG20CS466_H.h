#ifndef A2
#define A2
typedef struct node
{
    int vid;
    int rowNo;
    int colNo;
    struct node *next;
} node;

typedef struct Cord
{
    int x;
    int y;
} cord;

typedef struct graphdetails
{
    int vertices;
    node **gnode;
} graphdetails;

typedef struct queue
{
    cord *q;
    int front;
    int rear;
    int cap;
} queue;

void q_init(queue *p);
void enq(queue *p, cord ele);
cord leq(queue *p);
cord deq(queue *p);
int isempty(queue *p);
int findRows();
node *source(graphdetails *graph, int x, int y);
void createGraph(graphdetails *graph);
void insGraph(graphdetails *graph, int i, int j, int vid);
void readGraph(graphdetails *graph, int *start_x, int *start_y, int *end_x, int *end_y);
void printGraph(graphdetails *graph);
node *find(graphdetails *graph, node *curr, int k);
void dfst(graphdetails *graph, queue *q, node *curr, int end_x, int end_y, int *flag);
void bfst(graphdetails *graph, queue *q, node *curr, int end_x, int end_y, int *flag);
void findPath(graphdetails *graph, queue *qDFS, queue *qBFS, node *start, int end_x, int end_y);
void storePath(queue *qDFS, queue *qBFS);

#endif