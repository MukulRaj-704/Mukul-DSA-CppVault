class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(26,0);
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        
        for(int i=0;i<n;i++){
            arr1[s[i]-'a']++;
            arr1[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr1[i]!=0) return false;
        }
        return true;
    }
};
