// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> dist(1e5,INT_MAX);
        const int MOD = 1e5;
        q.push({0,start});
        dist[start] = 0;
        while(!q.empty())
        {
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            for(int i = 0; i<arr.size();i++)
            {
                int prod = node*arr[i];
                if(prod>MOD) 
                {
                    prod = prod % MOD;
                }
                if(steps + 1 < dist[prod])
                {
                    dist[prod] = steps + 1;
                    q.push({dist[prod],prod});
                }
            }
            
        }
        if(dist[end] == INT_MAX) return -1;
        else return dist[end];
    }
};
