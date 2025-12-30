class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for(int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;

            for(int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};

// n*n approach 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        stack<int>st;
        for(int i=1;i<=numRows;i++){
            vector<int>res;
            for(int j=0;j<i;j++){
                if(j==0) res.push_back(1);
                else if( j==i-1) res.push_back(1);
                else {
                    if(st.empty()) break;
                    int x=st.top();
                    st.pop();
                    int y = st.top();
                    res.push_back(x+y);
                }
            }
            while(!st.empty()) st.pop();
            ans.push_back(res);
            for(int j=0;j<i;j++){
                st.push(res[j]);
            }
        }
        return ans;
    }
};
