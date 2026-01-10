
class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
    }
    int atMostK(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, countOdd = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        if (arr[right] % 2 != 0)
            countOdd++;

        while (countOdd > k) {
            if (arr[left] % 2 != 0)
                countOdd--;
            left++;
        }

        ans += (right - left + 1);
    }
    return ans;
}
};
