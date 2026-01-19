class Solution {
  public:
    string reverseWords(string &s) {
        int n= s.size();
        int i=0;
        while(i<n){
            while(s[i]==' ') i++;
            if(i>=n) break;
            int start=i;
            while(i<n&&s[i]!=' ') i++;
            int end=i-1;
            while(start<end){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            
        }
        i=0;
        int write=0;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            if(write>0) s[write++]=' ';
            while(i<n&&s[i]!=' '){
                s[write++]=s[i++];
            }
        }
        s.resize(write);
        return s;
    }
};
