class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(n!=m) return false;
        s=s+s;
        if(s.find(goal)!=string::npos){
            return true;
        }
        return false;
    }
};


// Approach---2
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        string org=s;
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            s=org;
            reverse(s.begin(),s.begin()+i);
            reverse(s.begin()+i,s.end());
             reverse(s.begin(),s.end());
            if(s==goal) {
                return true;
            }
        }
        return false;
    }
};
