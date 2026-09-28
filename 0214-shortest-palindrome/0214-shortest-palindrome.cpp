class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin() , rev.end());
        string pat = s + '#' + rev;
        int i = 0 , j = 1 , n = pat.size();
        vector<int> lps(n , 0);

        while(j < n){
            if(pat[j] == pat[i]){
                lps[j] = i + 1;
                i++;
                j++;
            }
            else if(i == 0){
                j++;
            }
            else{
                i = lps[i - 1];
            }
        }

        int len = lps[n - 1];
        string add = s.substr(len);
        reverse(add.begin() , add.end());

        return add + s;
    }
};