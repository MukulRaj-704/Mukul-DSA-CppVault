class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        vector<int> res;
        queue<int> q; 
        for (int i=0; i<n;i++) {
            if(arr[i]<0)
                q.push(i);
            if(!q.empty()&&q.front()==i-k)
                q.pop();
            if(i>=k-1){
                if (!q.empty())
                    res.push_back(arr[q.front()]);
                else
                    res.push_back(0);
            }
        }
        return res;
    }
};
