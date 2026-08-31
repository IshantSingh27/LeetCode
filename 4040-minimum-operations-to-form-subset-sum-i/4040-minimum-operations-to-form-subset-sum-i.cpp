class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> dp(sum + 1 , INT_MAX);
        dp[0] = 0;

        for(int x : nums){
            vector<pair<int , int>> options;

            options.push_back({x , 0});

            int cost = 0 , val = x;
            while(val > 0){
                val = val / 2;
                cost++;

                if(val == 0) break;

                options.push_back({val , cost});
            }

            cost = 0 ; val = x;
            while(val <= sum / 2){
                val = val * 2;
                cost++;

                options.push_back({val , cost});
            }

            vector<int> ndp = dp;
            for(int s=0 ; s<=sum ; s++){
                if(dp[s] == INT_MAX) continue;

                for(auto [value , operations] : options){
                    if(s + value > sum) continue;

                    ndp[s + value] = min(ndp[s + value] , dp[s] + operations);
                }
            }
            dp = ndp;
        }

        return dp[sum] == INT_MAX ? -1 : dp[sum];

    }
};