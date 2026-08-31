class Solution {
public:
    int sol(int ind , int sum , vector<int>& nums , vector<vector<int>>& dp){
        if(sum == 0) return 0;
        if(ind == nums.size() || sum < 0) return INT_MAX;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int ops = sol(ind + 1 , sum , nums , dp);

        int cur = nums[ind] , cnt = 0 , res;
        while(cur <= sum){
            res = sol(ind + 1 , sum - cur , nums , dp);

            if(res != INT_MAX) ops = min(ops , cnt + res);

            cur = cur * 2;
            cnt++;
        }

        cur = nums[ind] , cnt = 0;
        while(cur > 0){
            res = sol(ind + 1 , sum - cur , nums , dp);

            if(res != INT_MAX) ops = min(ops , cnt + res);
            
            cur = cur / 2;
            cnt++;
        }

        return dp[ind][sum] = ops;
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(sum + 1 , -1));

        int res = sol(0 , sum , nums , dp);
        if(res == INT_MAX) return -1;
        else return res;
    }
};