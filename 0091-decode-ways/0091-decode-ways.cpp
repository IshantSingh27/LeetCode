class Solution {
public:
    int sol(int ind , string s , vector<int>& dp){
        if(ind < 0) return 1;

        if(dp[ind] != -1) return dp[ind];

        int one = 0 , two = 0;

        if(s[ind] != '0'){
            one = sol(ind - 1 , s , dp);
        }
        
        if(ind >= 1 && s[ind - 1] != '0' && (s[ind - 1] - '0') * 10 + (s[ind] - '0') <= 26){
            two = sol(ind - 2 , s , dp);
        }

        return dp[ind] = one + two;
    }
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n , -1);

        return sol(n - 1 , s , dp);
    }
};