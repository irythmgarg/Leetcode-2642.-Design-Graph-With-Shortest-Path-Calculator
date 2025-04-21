# Leetcode-2642.-Design-Graph-With-Shortest-Path-Calculator
📐 Dynamic Directed Graph with Shortest Path Queries
This class represents a directed weighted graph that supports:

Initialization with edges.

Adding new edges at runtime.

Finding the shortest path from a source node to a destination.
---
📦 Features
Graph Initialization

Constructor accepts n nodes and a list of directed edges: [from, to, weight].

Add Edge

Dynamically add a new edge to the graph using addEdge().

Shortest Path

Use a modified BFS/Dijkstra approach to compute the shortest path from src to dst.

🔍 Approach
---
The graph is stored as an adjacency list using unordered_map.

A distance array tracks the minimum cost to each node.

A queue is used to process nodes whose distance gets updated (similar to SPFA or Dijkstra without a priority queue).

🧠 Key Observations
---
This approach works efficiently for graphs without negative weights.

Time complexity depends on number of nodes and edges, making it efficient for sparse graphs.

🕰️ Time and Space Complexity
---
Operation	Complexity
Initialization	O(E)
Add Edge	O(1)
Shortest Path Query	O(V + E)
Where:

V = number of nodes

E = number of edges

🛠️ Example Usage
cpp
Graph g(4, {{0,1,5},{0,2,10},{1,3,2}});
g.addEdge({2,3,1});
int cost = g.shortestPath(0, 3);  // Output: 8 (0->2->3)
✅ Use Cases
Dynamic routing systems

Real-time path updates

Graphs that evolve with new connections
