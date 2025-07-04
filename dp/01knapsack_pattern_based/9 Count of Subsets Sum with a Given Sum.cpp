class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int dp[n + 1][target + 1];

        // Initialize first column: there's one way to get sum 0 — pick nothing
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Initialize first row (except dp[0][0]) to 0 because with 0 elements, we can't form any positive sum
        for (int j = 1; j <= target; j++) {
            dp[0][j] = 0;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};
