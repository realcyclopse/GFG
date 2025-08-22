// User function Template for C++
class Solution {
public:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i].first;
            if (!vis[neigh]) {
                dfs(neigh, adj, vis, st);
            }
        }
        st.push(node);  // push after visiting all neighbors
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort using DFS
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Step 3: Relax edges in topo order
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // source assumed = 0

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (dist[u] != INT_MAX) {
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i].first;
                    int wt = adj[u][i].second;
                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Step 4: Replace INT_MAX with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
