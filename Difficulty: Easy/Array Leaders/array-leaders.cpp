

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> res;
        int i = arr.size() -1;
        int max = arr[i];
        for( i-1 ; i >= 0 ; i--)
        {
            if(max<= arr[i])
            {
                max = arr[i];
                res.push_back(max);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};