class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size() , i = 0 , j = 1;
        vector<int> lps(n , 0);

        while(j < n){
            if(s[i] == s[j]){
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

        return s.substr(0 , len);
    }
};