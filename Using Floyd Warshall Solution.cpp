class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> mp; // adjacency list: node -> list of (neighbor, weight)
    int n;
    vector<vector<int>> ans; // matrix to store all-pairs shortest paths

    // Constructor to initialize graph with n nodes and given edges
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        ans.resize(n);
        for (int i = 0; i < n; ++i)
            ans[i].resize(n, INT_MAX); // initialize all distances as infinity

        for (auto& edge : edges) {
            mp[edge[0]].push_back({edge[1], edge[2]}); // store original edge
        }

        // Set distance from node to itself as 0
        for (int i = 0; i < n; i++) ans[i][i] = 0;

        // Initialize direct edge distances
        for (int u = 0; u < n; u++) {
            for (auto& [v, w] : mp[u]) {
                ans[u][v] = w;
            }
        }

        // Floyd-Warshall algorithm for all-pairs shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (ans[i][k] < INT_MAX && ans[k][j] < INT_MAX)
                        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                }
            }
        }
    }

    // Add an edge and update shortest paths if needed
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (ans[u][v] <= w) return; // No update needed

        mp[u].push_back({v, w});
        ans[u][v] = w;

        // Update paths using the new edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][u] < INT_MAX && ans[v][j] < INT_MAX)
                    ans[i][j] = min(ans[i][j], ans[i][u] + w + ans[v][j]);
            }
        }
    }

    // Return shortest path from src to dst
    int shortestPath(int src, int dst) {
        return ans[src][dst] == INT_MAX ? -1 : ans[src][dst];
    }
};
