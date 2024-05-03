#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_PLANETS 500
#define INF INT_MAX

char name[MAX_PLANETS][4];

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
}

int min(int a, int b) {
    return a < b ? a : b;
}

int bfs(int n, int source, int destination, int capacity[MAX_PLANETS][MAX_PLANETS], int parent[])
{
    int visited[MAX_PLANETS] = {0};
    int queue[MAX_PLANETS];
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = 1;
    parent[source] = -1;

    while (front < rear) 
    {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (!visited[v] && capacity[u][v] > 0) 
            {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return visited[destination];
}

int edmonds_karp(int n, int source, int destination, int capacity[MAX_PLANETS][MAX_PLANETS])
{
    int u, v;
    int parent[MAX_PLANETS];
    int max_flow = 0;

    while (bfs(n, source, destination, capacity, parent)) 
    {
        int path_flow = INF;
        for (v = destination; v != source; v = parent[v]) 
        {
            u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }
        for (v = destination; v != source; v = parent[v]) 
        {
            u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    char source_planet[4], destination_planet[4];
    int n;
    int capacity[MAX_PLANETS][MAX_PLANETS] = {0};

    scanf("%s %s %d", source_planet, destination_planet, &n);

    for (int i = 0; i < n; i++) 
    {
        char source_satellite[4], destination_satellite[4];
        int cap;
        scanf("%s %s %d", source_satellite, destination_satellite, &cap);
        capacity[Find(source_satellite)][Find(destination_satellite)] += cap;
    }

    int source = Find(source_planet);
    int destination = Find(destination_planet);

    int min_capacity = edmonds_karp(MAX_PLANETS, source, destination, capacity);
    printf("%d\n", min_capacity);

    return 0;
}

