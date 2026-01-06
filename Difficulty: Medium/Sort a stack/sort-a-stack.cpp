class Solution {
  public:
    void sortInsert(int val,stack<int> &st)
    {
        if(st.empty() || val>= st.top()) st.push(val);
        else
        {
            int temp = st.top();
            st.pop();
            sortInsert(val,st);
            st.push(temp);
        }
    }
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        sortStack(st);
        sortInsert(x,st);
        
    }
};
