class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area=0;
        vector<int> nextsmall(n,n);
        vector<int> prevsmall(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nextsmall[i]=st.top();
            }
            st.push(i);
        }
        // while(!st.empty()){
        //     st.pop();
        // }
         st= stack<int> ();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                prevsmall[i]= st.top();
            }
            st.push(i);
        }
        for(int  i=0;i<n;i++){
            int width = nextsmall[i]-prevsmall[i]-1;
            area = max(area, width*heights[i]);
        }
        return area;
    }
};
