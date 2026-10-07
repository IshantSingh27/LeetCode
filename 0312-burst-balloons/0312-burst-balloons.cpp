class Solution {
public:
    int sol(int i , int j , vector<int>& arr , vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        int maxi = -1e9;
        for(int k = i ; k<=j ; k++){
            int ans = arr[i - 1] * arr[k] * arr[j + 1] + sol(i , k - 1 , arr , dp) + 
            sol(k + 1 , j , arr , dp);

            maxi = max(maxi , ans);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n , vector<int>(n , -1));

        return sol(1 , n - 2 , nums , dp);
    }
};