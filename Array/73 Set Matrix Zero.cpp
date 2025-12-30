class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rowcheck=0;
        int colcheck=0;
        for(int j =0;j<m;j++){
            if(matrix[0][j]==0){
                rowcheck=1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                colcheck=1;
                break;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(rowcheck==1){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        if(colcheck==1){
            for(int j=0;j<n;j++){
                matrix[j][0]=0;
            }
        }
        
    }
};
