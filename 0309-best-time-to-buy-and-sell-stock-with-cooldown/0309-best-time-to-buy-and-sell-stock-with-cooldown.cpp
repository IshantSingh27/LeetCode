class Solution {
public:
    int sol(int ind, int buy, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind >= arr.size())
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int take = 0, nottake = 0;
        ;
        if (buy) {
            take = sol(ind + 1, 0, arr, dp) - arr[ind];
        }
        if (!buy) {
            nottake = arr[ind] + sol(ind + 2, 1, arr, dp);
        }
        int skip = sol(ind + 1, buy, arr, dp);

        return dp[ind][buy] = max({take, nottake, skip});
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));

        // return sol(0 , 1 , arr , dp);

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                int take = 0, nottake = 0;
                if (buy) {
                    take = dp[ind + 1][0] - arr[ind];
                }
                if (!buy) {
                    nottake = arr[ind] + dp[ind + 2][1];
                }
                int skip = dp[ind + 1][buy];

                dp[ind][buy] = max({take, nottake, skip});
            }
        }

        return dp[0][1];
    }
};