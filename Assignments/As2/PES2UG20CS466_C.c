#include "PES2UG20CS466_H.h"
#include <stdlib.h>

int main()
{
    int start_x, start_y, end_x, end_y, n = 0;
    node *start;
    graphdetails *graph = (graphdetails *)malloc(sizeof(graphdetails));
    queue *qDFS = (queue *)malloc(sizeof(queue)), *qBFS = (queue *)malloc(sizeof(queue));
    n = findRows();
    graph->vertices = n;
    readGraph(graph, &start_x, &start_y, &end_x, &end_y);
    start = source(graph, start_x, start_y);
    findPath(graph, qDFS, qBFS, start, end_x, end_y);
    storePath(qDFS, qBFS);
    return 0;
}