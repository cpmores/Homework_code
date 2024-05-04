#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000

typedef struct Node
{
    int from;
    int to;
    int weight;
}Edge;

void change_edge(Edge* a, Edge* b)
{
    Edge* c = (Edge*)malloc(sizeof(Edge));
    *c = *a;
    *a = *b;
    *b = *c;
}
void sort_edge(Edge edge, int Ne)
{   
    
}
int main()
{
    int Nv, Ne;
    Edge edge[MAXN];
    scanf("%d%d", &Nv, &Ne);
    for(int i = 0; i < Ne; ++i)
    {
        scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].weight);
    }
    sort_edge(edge[MAXN], Ne);
}
