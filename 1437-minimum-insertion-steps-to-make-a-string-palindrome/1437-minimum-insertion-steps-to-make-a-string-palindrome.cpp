class Solution {
public:
    int solve(string s1 , string s2){
        int n = s1.size() , m = s2.size();
        vector<int> prev(m + 1 , 0) , cur(m + 1 , 0);
        for(int i=1 ; i<=n ; i++){
            for(int j=1  ; j<=m ; j++){
                if(s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
                else cur[j] = max(cur[j - 1] , prev[j]);
            }
            prev = cur;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin() , s2.end());
        return solve(s1 , s2);
    }
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};