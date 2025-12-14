class Solution {
private :
void dfs(int r, int c, vector<vector<int>> &visited,vector<vector<char>>& board){
    visited[r][c]=1;
    int n = board.size();
    int m = board[0].size();
    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};
    for(int i=0;i<4;i++){
        int nr = r+drow[i];
        int nc= c+dcol[i];
        if(nr>=0 && nr<n&& nc>=0&& nc<m && visited[nr][nc]==0&& board[nr][nc]=='O'){
            dfs(nr,nc,visited,board);
        }
    }
}
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && visited[0][j]==0 ){
                dfs(0,j,visited,board);
            }
            if(board[n-1][j]=='O'&& visited[n-1][j]==0){
                dfs(n-1,j,visited,board);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'&& visited[i][0]==0){
                dfs(i,0,visited,board);
            }
            if(board[i][m-1]=='O' && visited[i][m-1]==0){
                dfs(i,m-1,visited,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};
