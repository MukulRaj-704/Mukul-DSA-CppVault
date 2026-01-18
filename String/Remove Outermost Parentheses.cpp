//Approach 2 ---> you can use the stack also

class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        int n =s.size();
        int counter=0;
        string res;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(counter>0){
                    res.push_back(s[i]);
                }
                counter++;
            }
            else{
                counter--;
                if(counter>0){
                    res.push_back(s[i]);
                }
            }
        }
        return res;
    }
};


