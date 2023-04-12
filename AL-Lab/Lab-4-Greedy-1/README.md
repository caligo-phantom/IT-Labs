# Lab-4-Greedy-1

## Optimization Problem
Optimization problem is a type of problem where you try to find the best solution from a set of possible solutions. The goal is to maximize or minimize a certain objective function that represents the thing you are trying to optimize. For example, you might want to find the fastest route from one point to another, or the most cost-effective way to produce a product. To solve an optimization problem, you need to define the objective function and constraints that limit the possible solutions, and then use mathematical techniques to find the best solution.

## Greedy Technique
Greedy technique is a method of solving problems that involves making the locally optimal choice at each step in the hope of finding a global optimum solution. In other words, at each step, the algorithm chooses the option that seems to be the best in the short term, without considering the long-term consequences.

The idea behind the greedy technique is that by making the best possible decision at each step, you can eventually find the best overall solution. However, this is not always the case, and sometimes the locally optimal choice may lead to a suboptimal or even an incorrect result.

Greedy algorithms are often used for optimization problems such as finding the shortest path or the minimum spanning tree, where the locally optimal choice at each step leads to the globally optimal solution. However, they may not always work for more complex problems, and other techniques may be required to find the optimal solution.

## sort()
The syntax for the sort() function in C++ is as follows:
```cpp
sort(start_address, end_address, comparator_function);
```

## Container Loading Problem
The container loading problem is a classic optimization problem in which we need to find the optimal way to pack a set of items into a container with a fixed capacity, such that the space utilization is maximized while ensuring that none of the items are damaged during transportation.

## 0/1 Knapsack Problem
The 0/1 Knapsack Problem is a classic optimization problem in computer science and mathematics. It is a problem of selecting a subset of items from a given set of items, subject to a weight constraint, in such a way as to maximize the total value of the selected items.

## Topological Sorting
Topological sorting is a sorting algorithm used to sort directed acyclic graphs (DAGs) in a specific order. In other words, it is an algorithm to arrange the vertices of a graph in a linear order such that for every directed edge (u, v), vertex u comes before vertex v in that order.

The algorithm starts by finding a vertex with no incoming edges (in-degree of 0) and adds it to the output list. Then it removes all the outgoing edges from that vertex and repeats the process with the remaining vertices until all the vertices are visited. If there are still some vertices with incoming edges, then the graph contains a cycle and a topological ordering is not possible.