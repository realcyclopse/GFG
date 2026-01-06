class Solution {
  public:
    void bs(vector<string> &ans,int n,string s)
    {
        if(s.size() == n) 
        {
            ans.push_back(s);
            return;
        }
        else
        {
            bs(ans,n,s+"0");
            bs(ans,n,s+"1");
        }
    }
    vector<string> binstr(int n) {
        vector<string> ans;
        string s;
        bs(ans,n,s);
        return ans;
    }
};