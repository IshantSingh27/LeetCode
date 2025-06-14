class Solution {
public:
    bool check(string& s1 , string& s2){
        if(s1.size() + 1 != s2.size()) return false;
        int first = 0 , second = 0;
        while( (first < s1.size()) && (second < s2.size()) ){
            if(s1[first] == s2[second]){
                first++; second++;
            }
            else second++;
        }
        if( first == s1.size() ) return true;
        else return false;
    }
    static bool comp(string &s1 , string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin() , arr.end() , comp);
        int n = arr.size();
        vector<int> dp(n , 1);
        int maxi = 1;
        for(int cur = 1 ; cur < n ; cur++){
            for(int prev = 0 ; prev < cur ; prev++){
                if(check(arr[prev] , arr[cur]) && dp[cur] < dp[prev] + 1){
                    dp[cur] = dp[prev] + 1;
                }
            }
            maxi = max(maxi , dp[cur]);
        }
        return maxi;
    }
};