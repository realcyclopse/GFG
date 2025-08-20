class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        map<char, vector<char>> adj;
        map<char, int> ind;

        // Step 1: Add all unique characters as empty nodes
        for (int i = 0; i < n; i++) {
            string word = words[i];
            for (int j = 0; j < word.size(); j++) {
                char c = word[j];
                if (adj.find(c) == adj.end()) {
                    adj[c] = {}; // empty adjacency
                }
                if(ind.find(c) == ind.end())
                {
                    ind[c] = 0;
                }
            }
        }

        // Step 2: Build edges
        for (int i = 0; i < n - 1; i++) {
            string word = words[i];
            string next = words[i+1];
            if (word.size() > next.size() && word.substr(0, next.size()) == next) {
    return ""; // invalid order
}

            int len = min(word.size(), next.size());

            for (int j = 0; j < len; j++) {
                if (word[j] != next[j]) {
                    adj[word[j]].push_back(next[j]); // word[j] comes before next[j]
                    ind[next[j]] += 1; 
                    break; // only first mismatch matters
                }
            }
        }
        queue<char> q;
        string order = "";
        int j = 0;
        map<char,int>::iterator it;
        for (it = ind.begin(); it != ind.end(); it++) {
        if (it->second == 0) {
        q.push(it->first);
        }
        }
        while(!q.empty())
        {
            
            char node = q.front();
            q.pop();
            order+= node;
            for(int i = 0; i< adj[node].size();i++)
            {
                char neigh = adj[node][i];
                ind[neigh]--;
                if(ind[neigh]==0) q.push(neigh);
            }
        }
        if (order.size() < ind.size()) {
        return ""; // cycle detected, no valid ordering
        }

        return order;
    }
};
