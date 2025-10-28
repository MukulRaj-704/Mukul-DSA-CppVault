class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int fl = INT_MIN;
        int sl = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>fl){
                sl = fl;
                fl = arr[i];
            }
            else if(sl<arr[i] && arr[i]!=fl){
                sl = arr[i];
            }
        }
        if(sl == INT_MIN){
            return -1;
        }
        return sl;
    }
};
