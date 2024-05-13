# Graph

## 1. Definitions

+ Undirected graph
+ Directed graph
+ Restrictions:
  + self loop is illegal
  + Multigraph is not considered

> Subgraph
>
> Path 

(connected) component of  an undirected G := the maximal connected subgraph

+ a tree : a graph that is connected and acyclic
+ a DAG: a direct acyclic graph: (有向回环图)
+ Strongly connected directed graph C: considered the direction to the edges.
+ Weakly connected: not considered the direction to the edges.   

## 2. Representation of Graphs

+ Adjacency Matrix (connected is true, disconnected is false)
+ Adjacency Lists (replace each row by a linked list)

## 3. Topological Sort

### 1. Implementation

```c
#include <stdio.h>
int main()
{
    const int N = S;
    int graph[5][5] = {{1, 0, 1, 0, 0}. {0, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}};
    int indeg[N] = {0, 0, 0, 0, 0};
    int res[N];
    for (int i = 0; i < N; ++i)
    {
        indeg[i] = 0;
        res[i] = 0;
    }
    //count the indeger of the node, store them in the indeg
    
}
```

## 4. Shortest Path Algorithm

