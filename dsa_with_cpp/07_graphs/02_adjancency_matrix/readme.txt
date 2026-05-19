Matrix Representation Basics
Add/Delete Edge in Matrix
BFS using Matrix
DFS Recursive using Matrix
DFS Iterative using Matrix
Connected Components using Matrix
Cycle Detection (Undirected) using Matrix
Cycle Detection (Directed) using Matrix
Bipartite Graph Check using Matrix
Topological Sort understanding with Matrix
Floyd Warshall Algorithm
Transitive Closure Warshall Algorithm

Sparse Graph:
    - Very few edges
    - E << V²
    - Most nodes are NOT connected
    - Best Representation → Adjacency List
    - Space Efficient

Dense Graph:
    - Large number of edges
    - E ≈ V²
    - Most nodes ARE connected
    - Best Representation → Matrix
    - Fast edge lookup
Matrix vs Adjacency List Tradeoffs

Adjacency Matrix:
    - Uses 2D array
    - Space → O(V²)
    - Edge lookup → O(1)
    - DFS/BFS → O(V²)
    - Good for dense graphs
    - Easy to implement
    - Bad for huge sparse graphs

Adjacency List:
    - Stores neighbors only
    - Space → O(V + E)
    - Edge lookup → O(degree)
    - DFS/BFS → O(V + E)
    - Good for sparse graphs
    - Memory efficient
    - Best for real-world large graphs
Memory Cost Analysis of Matrix

Matrix size:
    - V × V cells
    - Space → O(V²)

Example:
    - 1000 vertices
    - Matrix = 1000 × 1000
    - Total cells = 1,000,000

Problem:
    - Memory allocated even if edges do not exist
    - Very wasteful for sparse graphs

Huge Graph Example:
    - 1 million vertices
    - Need 10¹² cells
    - Practically impossible in RAM


When Matrix is Better Than List

Use Matrix when:
    - Graph is dense
    - Frequent edge lookup required
    - Small/medium graph size
    - Need simple implementation
    - Algorithms require matrix:
    - Warshall
    - Floyd–Warshall
    - Transitive Closure

Main Advantage:
    - Edge check in O(1)

Main Disadvantage:
    - High memory usage
