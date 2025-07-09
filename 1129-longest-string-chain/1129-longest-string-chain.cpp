class Solution {
public:
    bool solve(string s1 , string s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0 , second = 0;
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else first++;
        }

        return second == s2.size();
    }
    static bool comp(string s1 , string s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin() , arr.end() , comp);

        int n = arr.size() , ans = 0;
        vector<int> dp(n , 1);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<=i ; j++){
                if(solve(arr[i] , arr[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans , dp[i]);
        }

        return ans;
    }
};