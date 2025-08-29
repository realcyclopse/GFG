class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected
        }

        // min-heap: {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> vis(V, 0);

        q.push({0, 0});  // start from node 0
        int sum = 0;

        while (!q.empty()) {
            auto [wt, node] = q.top();
            q.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for (auto &[nbr, w] : adj[node]) {
                if (!vis[nbr]) {
                    q.push({w, nbr});
                }
            }
        }
        return sum;
    }
};
