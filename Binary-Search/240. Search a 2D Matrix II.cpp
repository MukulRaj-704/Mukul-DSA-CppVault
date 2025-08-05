OPTIMAL SOLUTION

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r = matrix.size();
       int c = matrix[0].size();
       int row=0;
       int col=c-1;
       while(row<r && col>=0){
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]>target){
            col--;
        }
        else if(matrix[row][col]<target){
            row++;
        }
       }
    return false; }
  
};
##################################################################################################

BETTER APPROACH 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r = matrix.size();
       int c = matrix[0].size();
       for(int i=0;i<r;i++){
        if(search(matrix[i],target)){
            return true;
        }
        
       }
  return false;
    }
   bool search(vector<int>&arr, int k){
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==k){
                return true;
            }
            if(arr[mid]>k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
  return false; }
};
