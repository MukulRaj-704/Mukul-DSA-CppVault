class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int presentcolor = image[sr][sc];
        int newcolor = color;
        vector<vector<int>> ans = image;
        int drow[]= {-1,0,+1,0};
        int dcol[]= {0,+1,0,-1};
        dfs(sr,sc,image,ans,presentcolor, newcolor,drow,dcol);
        return ans;
    }
private:
    void dfs(int row, int col, vector<vector<int>>&image, vector<vector<int>>& ans, int presentcolor, int newcolor, int drow[], int dcol[]){
        ans[row][col]=newcolor;
        int n = image.size();
        int m = image[0].size();
        for(int i= 0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==presentcolor && ans[nrow][ncol]!=newcolor ){
                dfs(nrow,ncol,image,ans,presentcolor,newcolor,drow,dcol);
            }
        }
    }
};
