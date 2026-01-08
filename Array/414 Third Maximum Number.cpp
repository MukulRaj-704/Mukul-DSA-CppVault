class Solution {
public:
    int thirdMax(vector<int>& nums) {
       long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;

        for (int x : nums) {
            if (x == first || x == second || x == third) continue;

            if (x > first) {
                third = second;
                second = first;
                first = x;
            } else if (x > second) {
                third = second;
                second = x;
            } else if (x > third) {
                third = x;
            }
        }

        return (third == LLONG_MIN) ? first : third;
    }
};
---------------------------------------------------------------------------------------------------
  public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        set <int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        if(st.size()<3) return*prev(st.end());
        for(int i=0;i<2;i++){
            st.erase(prev(st.end()));
        }
        return *prev(st.end());
    }
};
