# Leetcode-2642.-Design-Graph-With-Shortest-Path-Calculator

## 🏛 Dynamic Graph with Support for Shortest Path Queries

This module provides two approaches to represent a **dynamic weighted directed graph**:

1. **Dijkstra-like Approach (BFS with Queue)**
2. **Floyd-Warshall Approach (All-Pairs Shortest Paths)**

---

## 📦 Features Comparison

| **Feature**                    | **Dijkstra-like Approach** | **Floyd-Warshall Approach** |
|---------------------------------|----------------------------|-----------------------------|
| **Add Edge Support**            | ✅                         | ✅                          |
| **Shortest Path (src → dst)**   | ✅                         | ✅                          |
| **Best for Dense Graphs**       | ❌                         | ✅                          |
| **Best for Sparse Graphs**      | ✅                         | ❌                          |
| **All-Pairs Shortest Path**     | ❌                         | ✅                          |

---

## 1️⃣ Dijkstra-like Approach

### Key Ideas:
- Uses `unordered_map` as adjacency list.
- Performs **queue-based traversal** to compute shortest path.
- Efficient for **sparse graphs** or when **queries are rare**.

### Complexity:
- **Initialization:** O(E)
- **Shortest Path Query:** O(V + E)
- **Add Edge:** O(1)

---

## 2️⃣ Floyd-Warshall Approach

### Key Ideas:
- Precomputes **all-pairs shortest paths**.
- Updates path matrix when new edge is added.
- Great for **dense graphs** or when **multiple queries** are expected.

### Complexity:
- **Initialization:** O(V³)
- **Shortest Path Query:** O(1)
- **Add Edge:** O(V²)

---

## 🧪 Example Usage

```cpp
// Dijkstra-like
Graph g1(4, {{0,1,5},{0,2,10},{1,3,2}});
g1.addEdge({2,3,1});
int cost1 = g1.shortestPath(0, 3); // Output: 8

// Floyd-Warshall
Graph g2(3, {{0,1,2},{1,2,3}});
g2.addEdge({0,2,10});
int cost2 = g2.shortestPath(0, 2); // Output: 5
