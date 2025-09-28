// User function Template for C++

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        int count=0;
        int n =st.size();
        deleteele(st,count,n,x);
        return st;
    }
    void deleteele(stack<int>&st, int &count, int s,int x){
        if(count==s){
            st.push(x);
            return ;
        }
        int num = st.top();
        st.pop();
        count++;
        deleteele(st,count,s,x);
        st.push(num);
    }
};
