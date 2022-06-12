#include <iostream>

using namespace std;

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList *)malloc(
        V * sizeof(struct AdjList));

    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct AdjListNode *check = NULL;
    struct AdjListNode *newNode = newAdjListNode(dest);

    if (graph->array[src].head == NULL)
    {
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
    }
    else
    {
        check = graph->array[src].head;
        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = newNode;
    }
    newNode = newAdjListNode(src);
    if (graph->array[dest].head == NULL)
    {
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
    else
    {
        check = graph->array[dest].head;
        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = newNode;
    }
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n %d", v, v);
        while (pCrawl)
        {
            printf(" -> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 12;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 7);
    addEdge(graph, 0, 11);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 6);
    addEdge(graph, 1, 9);
    addEdge(graph, 1, 10);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 7);
    addEdge(graph, 3, 9);
    addEdge(graph, 3, 10);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 6);
    addEdge(graph, 4, 8);
    addEdge(graph, 4, 9);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 3);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 1);
    addEdge(graph, 6, 4);
    addEdge(graph, 6, 5);
    addEdge(graph, 6, 11);
    addEdge(graph, 7, 0);
    addEdge(graph, 7, 3);
    addEdge(graph, 7, 8);
    addEdge(graph, 7, 9);
    addEdge(graph, 8, 2);
    addEdge(graph, 8, 4);
    addEdge(graph, 8, 7);
    addEdge(graph, 8, 10);
    addEdge(graph, 9, 1);
    addEdge(graph, 9, 3);
    addEdge(graph, 9, 4);
    addEdge(graph, 9, 7);
    addEdge(graph, 10, 1);
    addEdge(graph, 10, 3);
    addEdge(graph, 10, 8);
    addEdge(graph, 11, 0);
    addEdge(graph, 11, 6);

    printGraph(graph);
    return 0;
}
