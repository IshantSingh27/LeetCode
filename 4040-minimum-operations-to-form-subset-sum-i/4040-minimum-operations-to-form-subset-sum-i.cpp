class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {

        const int INF = 1e9;

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;

        for (int x : nums) {

            // value -> minimum operations needed
            vector<pair<int, int>> options;

            // Keep x as it is
            options.push_back({x, 0});

            // Divide: x/2, x/4, x/8, ...
            int val = x;
            int cost = 0;

            while (val > 0) {
                val /= 2;
                cost++;

                if (val == 0)
                    break;

                options.push_back({val, cost});
            }

            // Multiply: 2*x, 4*x, 8*x, ...
            val = x;
            cost = 0;

            while (val <= sum / 2) {
                val *= 2;
                cost++;

                options.push_back({val, cost});
            }

            // 0/1 knapsack transition
            vector<int> ndp = dp;

            for (int s = 0; s <= sum; s++) {

                if (dp[s] == INF)
                    continue;

                for (auto [value, operations] : options) {

                    if (s + value > sum)
                        continue;

                    ndp[s + value] =
                        min(ndp[s + value],
                            dp[s] + operations);
                }
            }

            dp = ndp;
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};