void bfs(Graph G, int source, int visited[MaxVertices+1][MaxVertices+1])
{
    PtrToVNode queue[1000];
    int front = 0;
    int rear = 0;
    PtrToVNode u = G -> Array[source];
    while(u)
    {
        queue[rear++] = u;
        visited[source][u -> Vert] = 1;
        u = u -> Next;
    }
    visited[source][source] = 1;
    while(front < rear)
    {
        PtrToVNode u = queue[front++];
        visited[source][u -> Vert] = 1;
        PtrToVNode v = G -> Array[u -> Vert];
        while(v)
        {
            if(!visited[source][v -> Vert])
                queue[rear++] = v;
            visited[source][v -> Vert] = 1;
            v = v -> Next;
        }
    }
}
void check(Graph G, int ans[MaxVertices+1][MaxVertices+1], int visited[MaxVertices+1][MaxVertices+1])
{
    for(int i = 0; i < G -> NumOfVertices; ++i)
    {
        if(ans[i][0] == -1)
            continue;
        for(int j = 0; j < G -> NumOfVertices;++j)
        {
            if(i == j)
            {
                ans[i][i] = 1;
            }
            else if(i != j&&visited[i][j] == 1 && visited[j][i] == 1)
            {
                ans[i][j] = 1;
                ans[j][0] = -1;
                //printf("%d %d %d\n", i, j, ans[i][j]);
            }
        }
    }
}
void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) )
{
    int ans[MaxVertices+1][MaxVertices+1] = {{0}};
    int visited[MaxVertices+1][MaxVertices+1] = {{0}};
    if(G -> NumOfVertices > 1)
    {
        for(int i = 0; i < G -> NumOfVertices; ++i)
            bfs(G, i, visited);
        check(G, ans, visited);
        //printf("%d %d %d\n", 3, 3, ans[3][3]);
        for(int i = 0; i < G -> NumOfVertices; ++i)
        {
            if(ans[i][0] == -1)
                continue;
            for(int j = 0; j < G -> NumOfVertices; ++j)
            {
                if(ans[i][j] == 1)
                (*visit)(j);
            }
            putchar(10);
        }
    }
    else
    {
        (*visit)(0);
    }
/*    for(int i = 0; i <= 9;++i)
    {
        for(int j =0; j <= 9;++j)
        {
            printf("%d ", ans[i][j]);
        }
        putchar(10);
    }
    putchar(10);
    for(int i = 0; i <= 9;++i)
    {
        for(int j =0; j<= 9;++j)
        {
            printf("%d ", visited[i][j]);
        }
        putchar(10);
    }*/
}