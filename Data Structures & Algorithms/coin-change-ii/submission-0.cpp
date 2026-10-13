class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int ind = 0; ind < n; ind++) {
            for (int target = 1; target <= amount; target++) {
                int notTake = ind == 0 ? 0 : dp[ind - 1][target];
                int take = 0;
                if (coins[ind] <= target) {
                    take = dp[ind][target - coins[ind]];
                }
                dp[ind][target] = take + notTake;
            }
        }
        return dp[n - 1][amount];
    }
};
