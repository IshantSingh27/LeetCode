class Solution {
public:
    bool sol(int ind , string s , unordered_set<string> &mp , vector<int>& dp){
        if(ind == s.size()) return true;

        if(dp[ind] != -1) return dp[ind];

        for(int i=ind ; i<s.size() ; i++){
            string temp = s.substr(ind , i - ind + 1);

            if(mp.count(temp)){
                if(sol(i + 1 , s , mp , dp)) return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& arr) {
        unordered_set<string> mp(arr.begin() , arr.end());

        int n = s.size();
        // vector<int> dp(n , -1);

        // return sol(0 , s , mp , dp);

        vector<int> dp(n + 1 , 0);
        dp[n] = 1;

        for(int ind=n - 1 ; ind>=0 ; ind--){
            for(int i=ind ; i<s.size() ; i++){
                string temp = s.substr(ind , i - ind + 1);

                if(mp.count(temp)){
                    if(dp[i + 1]) dp[ind] = true;
                }
            }
        }

        return dp[0];
    }
};