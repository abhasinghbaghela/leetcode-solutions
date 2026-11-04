class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n);
        for (int i = 0; i < n; i++) {
            prev[i] = i;
        }
        int maxi = 1;
        int last = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 &&
                    dp[j] + 1 > dp[i]) {

                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                last = i;
            }
        }
        vector<int> ans;
        while (prev[last] != last) {
            ans.push_back(nums[last]);
            last = prev[last];
        }
        ans.push_back(nums[last]);
        return ans;
    }
};