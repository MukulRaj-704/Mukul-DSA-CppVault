class Solution {
  public:
    bool checkRedundancy(string &s) {
        int n = s.length();
        stack<char> st;   

        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                bool retd = true;  
                while(!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')) {
                    retd = false;
                    st.pop();
                }
                if( st.top() == '(') {
                    st.pop();
                }

                if(retd == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
