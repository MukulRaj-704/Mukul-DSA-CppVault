class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n = mat.size();
        int m = mat[0].size();

        if(m==1 && n==1 ) return {0,0};
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            int maxrow=0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mat[maxrow][mid]){
                    maxrow=i;
                }
            }
            int top= (maxrow>0) ? mat[maxrow-1][mid] : -1;
            int bottom = (maxrow<n-1) ? mat[maxrow+1][mid] : -1;
            int left = (mid>0) ? mat[maxrow][mid-1] : -1;
            int right = mid<m-1 ? mat[maxrow][mid+1] : -1;

            int curr = mat[maxrow][mid];
            if(curr> top && curr> bottom && curr>left && curr>right) return {maxrow,mid};
            else if(mat[maxrow][mid]<right) low=mid+1;
            else high = mid-1;
        }
        return {};
    }
};
