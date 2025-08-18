class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> in(V, 0);
        vector<vector<int>> adj(V);

        // Build graph and indegree
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            in[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        // Process queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int neigh = adj[node][j];
                in[neigh]--;
                if (in[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        for(int i = 0;i<V;i++)
        {
            if(in[i]!=0) return true;
        }
        return false;
    }
};