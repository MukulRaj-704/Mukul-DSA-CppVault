class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        vector<pair<char,int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second; });
        string res;
        res.reserve(s.size()); 
        for(auto &p : v){
            res.append(p.second, p.first);
        }
        return res;
    }
};
