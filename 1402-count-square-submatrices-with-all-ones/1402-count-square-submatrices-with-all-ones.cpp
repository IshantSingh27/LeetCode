class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n , vector<int>(m , 0));
        for(int i=0 ; i<n ; i++) dp[i][0] = arr[i][0];
        for(int i=0 ; i<m ; i++) dp[0][i] = arr[0][i];
        //excluding base case
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                if(arr[i][j] == 0) continue; // keep it 0.
                dp[i][j] = min(dp[i - 1][j - 1] , min(dp[i][j - 1] , dp[i - 1][j])) + 1;
            }
        }
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }
};