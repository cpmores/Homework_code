#include <stdio.h>
#include <limits.h>
//put global variable here
#define MAXN 1000
#define IFN INT_MAX
int graph[MAXN][MAXN];
//
void input(int Ne, int graph[MAXN][MAXN])
{
    for(int i = 1; i <= Ne; i++)
    {
        int a, b, weight;
        scanf("%d%d%d", &a, &b, &weight);
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
}//input every edge and its weight 

void input_seq(int K,int Nv, int seq[100][MAXN])
{
    for(int i = 0; i < K; ++i)
        for(int j = 0; j < Nv;++j)
            scanf("%d", &seq[i][j]);
}//input the sequence that you have to test

void check_update(int index, int Nv, int vert[MAXN][2], int graph[MAXN][MAXN])
{
    for(int i = 1; i <= Nv; ++i)
    {
        if(graph[index][i] && vert[i][0] == 0)
        {
            if(vert[index][1] + graph[index][i] < vert[i][1])
            {
                vert[i][1] = vert[index][1] + graph[index][i];//update the minimum distance if the neighbour node provides a smaller one
            }
        }
    }
}
int check_min(int check_point, int Nv, int vert[MAXN][2], int graph[MAXN][MAXN] )
{
    int min = IFN;
    for(int i = 1; i <= Nv; ++i)
    {
        if(!vert[i][0] && vert[i][1] < min)
        {
            min = vert[i][1];
        }//find the minimum distance among the unvisited vertex.
    }
    if(vert[check_point][1] == min && !vert[check_point][0])
    {
        vert[check_point][0] = 1;//mark it visited
        check_update(check_point, Nv, vert, graph);//update the minimum distance
        return 1;
    }
    return 0;
}
int main()
{
    int seq[100][MAXN];
    int Ne,Nv;
    int K;

    scanf("%d%d", &Nv, &Ne);
    input( Ne, graph);
    
    scanf("%d", &K);
    input_seq(K, Nv, seq);
     
    for(int i = 0; i < K; ++i)
    {
        // for every seq
        int vert[MAXN][2];
        int flag = 0;//used to record whether the sequence is Dijkstra sequence
        for(int j = 1; j <= Nv; ++j)
        {
            vert[j][0] = 0;
            vert[j][1] = IFN;
        }//initialize the vert array
        for(int j = 0; j < Nv;++j)
        {
            if(j == 0)
            {
                vert[seq[i][j]][0] = 1;
                vert[seq[i][j]][1] = 0;
                check_update(seq[i][j], Nv, vert, graph);//update the node besides the source.
            }
            else
            {
                if(check_min(seq[i][j], Nv, vert, graph) == 0)
                {
                    ++flag;//if flag == 0, it means we found no answer .
                }
            }
        }
        if(flag)
        {   
            printf("No\n");
        }
        else 
        {
            printf("Yes\n");
        }
    }
}