# Application of Depth-First Search

## 1. Complementation

using stack to complement

## 2. Biconnectivity

+ Articulation point: the rest points cannot connect when deleting the point.
+ biconnected components: deleting one of the point will come to disconnection.

### 1) Find the biconnected components of a connected undirected G

+ Use depth first search to obtain a spanning tree of G.
  + the root is an articulation point if it has at least 2 children.
  + the rest vertex is articulation point if it has at least a child, and it child cannot go up to the higher without the vertex.

### 2) Euler Circuits

+ the graph is connected and each vertex has an even degree.
+ the graph is connected and there are exactly two vertices having odd degree.