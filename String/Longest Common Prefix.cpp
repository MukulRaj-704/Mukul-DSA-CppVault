class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        string common=strs[0];
        int m=common.size();
        for(int i=1;i<n;i++){
            string tocam=strs[i];
            int j=0;
            while(common[j]==tocam[j] && j<m && j<tocam.size()) j++;
            common =common.substr(0,j);
        }
        return common;
    }
};
