class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int size= s.size();
        int count=0;
        deleteele(s,count,size);
    }
    void deleteele(stack<int>&st,int &count,int s){
        int mid=s/2;
        if(count==mid){
            st.pop();
            return ;
        }
        int num = st.top();
        st.pop();
        count++;
        deleteele(st,count,s);
        st.push(num);
    }
};
