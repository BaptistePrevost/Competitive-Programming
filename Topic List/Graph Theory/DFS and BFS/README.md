# Idea

Go as deep into the graph as possible, and backtrack once you are at a vertex without any unvisited adjacent vertices.

# Applications

- Find lexicographical first path in the graph from source  to all vertices.
- Find the lowest common ancestor (LCA) of two vertices.
- Topological sorting
- Check whether a given graph is acyclic and find cycles in a graph.
- Find strongly connected components in a directed graph: First do a topological sorting of the graph. Then transpose the graph and run another series of depth first searches in the order defined by the topological sort. For each DFS call the component created by it is a strongly connected component.
- Find bridges in an undirected graph: First convert the given graph into a directed graph by running a series of depth first searches and making each edge directed as we go through it, in the direction we went. Second, find the strongly connected components in this directed graph. Bridges are the edges whose ends belong to different strongly connected components.