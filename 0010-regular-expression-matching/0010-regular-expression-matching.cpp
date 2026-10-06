class Solution {
public:
    bool sol(int i , int j , string s , string p , vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(j < 0) return false;
        if(i < 0){
            while(j >= 0){
                if(p[j] != '*') return false;
                j -= 2;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '.'){
            if(sol(i - 1 , j - 1 , s , p , dp)) return dp[i][j] = true;
        }
        else if(p[j] == '*'){
            bool zero = sol(i , j - 2 , s , p , dp);
            bool one = false;
            if(p[j - 1] == '.' || p[j - 1] == s[i]){
                one = sol(i - 1 , j , s , p , dp);
            }
            return dp[i][j] = one || zero;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));

        return sol(n - 1 , m - 1 , s , p , dp);
    }
};