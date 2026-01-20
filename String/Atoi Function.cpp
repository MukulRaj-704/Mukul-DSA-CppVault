class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        int flag=0;
        long long result=0;
        while(i<n && s[i]==' ') i++;
        if (i >= n) return 0;
         if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') flag = 1;
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
           result=result*10LL+(s[i]-'0');
           i++;
           if(flag==0 && result>INT_MAX) return INT_MAX;
           if(flag==1&&-result<INT_MIN) return INT_MIN;
        }
        if(flag==1) result=-result;
        return (int)result;
    }
};
            
