class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> sh(n, INT_MAX);
        queue<pair<int,int>> q;

        sh[src] = 0;
        q.push({src, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (int i = 0; i < adj[node].size(); i++) {
                int neigh = adj[node][i];
                if (sh[neigh] > dist + 1) {
                    sh[neigh] = dist + 1;
                    q.push({neigh, dist + 1});
                }
            }
            
        }
        for(int i = 0; i<n+1; i++)
            {
                if(sh[i]==INT_MAX)
                {
                    sh[i]=-1;
                }
            }
        return sh;
    }
};