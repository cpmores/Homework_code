#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000

int set[MAXN];
int flag_tot;
int flag;
typedef struct Node
{
    int from;
    int to;
    int weight;
}Edge;

void change_edge(Edge* a, Edge* b)
{
    Edge temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort_edge(Edge edge[MAXN], int Ne)
{
    for(int i = Ne; i > 0; ++i)
    {
        for(int j = 1;j < i; ++j)
        {
            if(edge[j].weight > edge[j+1].weight)
            {
                change_edge(&edge[j], &edge[j+1]);
            }
        }
    }
}
int Find(int index_1)
{
    if(set[index_1] == index_1)
        return set[index_1];
    return set[index_1] = Find(set[index_1]);
}
int check_Union(int index_1, int index_2)
{
    if(Find(index_1) == Find(index_2))
        return 0;
    return 1;//index don't union before
}
void Union(int index_1, int index_2)
{
    set[Find(index_1)] = Find(index_2);
}
int check_being(Edge edge[MAXN], int Ne, int Nv)
{
    int wei = 0;
    //if flag == 0, then the edge has not been visited.
    for(int i = 1; i < Ne; ++i)
    {
        if(flag == Nv - 1)
            return wei;
        int a = check_Union(edge[i + 1].from, edge[i + 1].to);
        if(check_Union(edge[i].from, edge[i].to))
        {
            wei += edge[i].weight;
            ++flag;
            Union(edge[i].from, edge[i].to);
        }
        if (a + check_Union(edge[i + 1].from, edge[i + 1].to) == 1)
        {
            flag_tot++;
        }
    }
    if(check_Union(edge[Ne].from, edge[Ne].to))
        {
            wei += edge[Ne].weight;
            ++flag;
            Union(edge[Ne].from, edge[Ne].to);
        }
    if(flag == Nv - 1)
            return wei;
    return 0;
}   
int main()
{
    int Nv, Ne;
    int weight;
    Edge edge[MAXN];
    scanf("%d%d", &Nv, &Ne);
    for(int i = 1; i <= Ne; ++i)
        scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].weight);
    sort_edge(edge, Ne);
    for(int i = 1; i <= Nv; ++i)
        set[i] = i;
    weight = check_being(edge, Ne, Nv); 
    if(weight == 0)
    {
        printf("No MST\n");
        printf("%d\n", ++flag);
    }
    else 
    {
        printf("%d\n", weight);
        if(!flag_tot)
        {
            printf("No\n");
        }
        else
            printf("Yes\n");
    }
    return 0;
}
