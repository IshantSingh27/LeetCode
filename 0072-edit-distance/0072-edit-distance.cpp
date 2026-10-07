class Solution {
public:
    int sol(int i , int j , string s1 , string s2 , vector<vector<int>>& dp){
        if(i < 0){
            if(j < 0) return 0;
            else return j + 1;
        }
        if(j < 0){
            return i + 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = sol(i - 1 , j - 1 , s1 , s2 , dp);
        else{
            int ins = 1 + sol(i , j - 1 , s1 , s2 , dp);
            int del = 1 + sol(i - 1 , j , s1 , s2 , dp);
            int rep = 1 + sol(i - 1 , j - 1 , s1 , s2 , dp);

            return dp[i][j] = min({ins , del , rep});
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();

        vector<vector<int>> dp(n , vector<int>(m , -1));

        return sol(n - 1 , m - 1 , s1 , s2 , dp);
    }
};