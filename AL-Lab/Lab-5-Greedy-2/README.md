# Lab-5-Greedy-2

## Spanning Tree
A spanning tree is a tree that spans all the nodes of a connected graph. In other words, it is a subset of the edges of the original graph that forms a tree connecting all the vertices. A tree is a connected graph with no cycles, so a spanning tree must have exactly n-1 edges, where n is the number of vertices in the original graph.

## Minimum Cost Spanning Tree
A minimum spanning tree is a subset of edges in an undirected weighted graph that connects all the vertices together without any cycles and has the minimum total edge weight possible. In simpler terms, it is the smallest possible set of edges that connects all the vertices in a graph and has the smallest possible total weight.

## Prim's Algorithm
Prim's algorithm is a greedy algorithm used to find the minimum spanning tree of a weighted undirected graph. It starts with a single vertex and then grows the tree one edge at a time, always adding the edge with the smallest weight that connects the tree to a new vertex.

The algorithm maintains two sets of vertices: one set contains the vertices already included in the minimum spanning tree, and the other set contains the vertices not yet included. At each step, the algorithm selects the vertex that is closest to the set of vertices already included in the minimum spanning tree.

The process continues until all vertices are included in the minimum spanning tree. At each step, the algorithm adds the selected edge to the minimum spanning tree and updates the distance of the vertices not yet included in the minimum spanning tree.

Prim's algorithm guarantees that the resulting minimum spanning tree is optimal, and it runs in O(E log V) time, where E is the number of edges and V is the number of vertices in the graph.

## Kruskal's Algorithm
Kruskal's Algorithm is an algorithm for finding the Minimum Spanning Tree (MST) of a connected, weighted graph. An MST is a subset of the edges of the graph that connects all vertices together with the minimum total edge weight. Kruskal's Algorithm works by initially sorting all the edges of the graph in non-decreasing order of their weight, and then iteratively adding the smallest edge to the MST as long as it does not create a cycle.

## Dijkstra's Algorithm
Dijkstra's Algorithm is a shortest path algorithm used to find the shortest path between a starting vertex and all other vertices in a weighted graph with non-negative edge weights. The algorithm starts by initializing the distance of the starting vertex to 0 and the distance of all other vertices to infinity. It then visits the vertex with the smallest distance from the starting vertex, called the "current vertex," and updates the distance of its neighbors if a shorter path is found. This process continues until all vertices have been visited, and the shortest path from the starting vertex to all other vertices is found.