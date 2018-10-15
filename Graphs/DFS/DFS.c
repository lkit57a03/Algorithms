#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int value;
    struct node * next;
};

struct Graph {
    int numVertices;
    int * visited;
    struct node ** adjLists;
};

struct node * createNode(int v){
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->value = v;
    newNode->next = NULL;
}

struct Graph * createGraph(int vertices){
    struct Graph * graph = malloc(sizeof(struct Graph));
    graph->numVertices   = vertices;
    graph->adjLists      = malloc(vertices * sizeof(struct node *));
    graph->visited       = malloc(vertices * sizeof(int));

    
    for(int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i]  = 0;
    }
    return graph;
    
}
void addEdges(struct Graph * graph,int src,int dest){
    struct node * newNode = createNode(dest);
    newNode->next         = graph->adjLists[src];
    graph->adjLists[src]  = newNode;

    newNode               = createNode(src);
    newNode->next         = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void printGraph(struct Graph * graph){
    
    for(int i = 0; i < graph->numVertices; i++)
    {
        struct node * newNode = graph->adjLists[i];
        printf("\n Adjacency List of vertex %d \n",i);

        while(newNode){
            printf("%d -> ",newNode->value);
            newNode = newNode->next;
        }
        printf("\n");
    }
}
void DFS(struct Graph* graph,int vertex){
    struct node * temp = graph->adjLists[vertex];
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while(temp != NULL){
        int connectedVertex = temp->value;

        if(graph->visited[connectedVertex] == 0){
            DFS(graph,connectedVertex);
        }
        temp = temp->next;
    }
}
