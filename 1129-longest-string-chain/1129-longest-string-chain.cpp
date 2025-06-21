class Solution {
public:
    int check(string s1 , string s2){
        if(s1.size() != 1 + s2.size()) return false;
        int first = 0 , second = 0;
        while(first < s1.size() && second < s2.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(second != s2.size()) return false;
        else return true;
    }
    static bool comp(string s1 , string s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin() , arr.end() , comp);
        int n = arr.size() , maxi = 0;
        vector<int> dp(n , 1);
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if(check(arr[ind] , arr[prev]) && dp[ind] < dp[prev] + 1){
                    dp[ind] = dp[prev] + 1;
                }
            }
            maxi = max(dp[ind] , maxi);
        }
        return maxi;
    }
};