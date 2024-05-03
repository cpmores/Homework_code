#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 501

char name[MAXN][4];

int Find(char* x)
{
    int flag = 0, index = 0;
    static int num = 0;
    for(int i = 0;i <= num;++i)
    {
        if(!strcmp(x, name[i]))
        {
            ++flag;
            index = i;
        }
    }
    if(flag)
        return index;
    ++num;
    strcat(name[num], x);
    return num;
}//fix not connected max N

int min(int a, int b) {
    return a < b ? a : b;
}

int bfs(int source, int destination, int graph[MAXN][MAXN], int parent[MAXN])
{
    int visited[MAXN] = {0};
    int queue[MAXN];
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = 1;
    parent[source] = -1;

    while (front < rear) 
    {
        int u = queue[front++];
        for (int v = 0; v < MAXN; ++v) {
            if (!visited[v] && graph[u][v] > 0) 
            {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return visited[destination];
}

int ek(int source, int destination, int graph[MAXN][MAXN])
{
    int u, v;
    int parent[MAXN];
    int flow = 0;

    while (bfs(source, destination, graph, parent)) 
    {
        int path_flow = 10000;
        for (v = destination; v != source; v = parent[v]) 
        {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }
        for (v = destination; v != source; v = parent[v]) 
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
        flow += path_flow;
    }
    return flow;
}

int main() {
    char source[4], destination[4];
    int n;
    int graph[MAXN][MAXN] = {0};

    scanf("%s %s %d", source, destination, &n);

    for (int i = 0; i < n; i++) 
    {
        char source_a[4], destination_b[4];
        int cap;
        scanf("%s %s %d", source_a, destination_b, &cap);
        graph[Find(source_a)][Find(destination_b)] += cap;
    }
    printf("%d\n", ek(Find(source), Find(destination), graph));
    return 0;
}
