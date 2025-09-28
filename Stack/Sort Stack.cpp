class Solution {
  public:
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int num = st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st, num);
    }
    
    void sortedInsert(stack<int>& st, int num) {
        if(st.empty() || st.top() <= num) {
            st.push(num);
            return;
        }
        int temp = st.top();
        st.pop();
        sortedInsert(st, num);
        st.push(temp);
    }
};
