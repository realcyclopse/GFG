class Solution {
  public:
    void ins(stack<int> &st, int val)
    {
        if(st.empty()) {
            st.push(val);
            return;
        }
        else
        {
            int x = st.top();
            st.pop();
            ins(st,val);
            st.push(x);
        }
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        else
        {
            int ele = st.top();
            st.pop();
            reverseStack(st);
            ins(st,ele);
            return;
            
            
        }
        
    }
};