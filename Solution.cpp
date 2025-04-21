class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> mp; // adjacency list: node -> list of (neighbor, weight)
    int n; // number of nodes

    // Constructor to initialize the graph with initial edges
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (auto a : edges) {
            mp[a[0]].push_back({a[1], a[2]}); // add directed edge a[0] -> a[1] with weight a[2]
        }
    }

    // Function to add an edge dynamically
    void addEdge(vector<int> edge) {
        mp[edge[0]].push_back({edge[1], edge[2]});
    }

    // Function to find the shortest path from src to dst using modified Dijkstra with a queue
    int shortestPath(int src, int dst) {
        vector<int> maxans(n, INT_MAX); // holds minimum cost to reach each node
        queue<pair<int, int>> q; // (node, current cost)
        maxans[src] = 0;
        q.push({src, 0});

        while (!q.empty()) {
            auto top = q.front();
            int node = top.first;
            int cost = top.second;
            q.pop();

            for (auto a : mp[node]) {
                int neighbor = a.first;
                int edgeCost = a.second;

                // Relax the edge if a shorter path is found
                if (maxans[neighbor] > cost + edgeCost) {
                    maxans[neighbor] = cost + edgeCost;
                    q.push({neighbor, cost + edgeCost});
                }
            }
        }

        return maxans[dst] == INT_MAX ? -1 : maxans[dst];
    }
};
