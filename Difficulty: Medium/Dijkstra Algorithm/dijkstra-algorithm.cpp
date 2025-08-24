// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        set<pair<int,int>> s;
        vector<int> dist(V,INT_MAX);
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        dist[src] = 0;
        s.insert({0,src});
        while(!s.empty())
        {
            auto it = *s.begin();
            int node = it.second;
            int dis = it.first;
            s.erase({dis,node});
            
            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int ew = it.second;
                
                if(dis + ew < dist[adjnode])
                {
                    if(dist[adjnode] != INT_MAX)
                    {
                        s.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode] = ew + dis;
                    s.insert({dist[adjnode],adjnode});
                    
                }
            }
        }
        return dist;
    }
};