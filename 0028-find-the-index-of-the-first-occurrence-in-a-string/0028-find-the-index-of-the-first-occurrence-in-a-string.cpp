class Solution {
public:
    void sol(string s , vector<int>& lps){
        int i = 0 , j = 1;
        while(j < s.size()){
            if(s[i] == s[j]){
                lps[j] = i + 1;
                i++;
                j++;
            }
            else{
                if(i == 0){
                    j++;
                }
                else{
                    i = lps[i - 1];
                }
            }
        }
    }
    int strStr(string s, string pat) {
        int m = pat.size() , n = s.size() , i = 0 , j = 0;
        vector<int> lps(m , 0);
        sol(pat , lps);

        while(i < n && j < m){
            if(s[i] == pat[j]){
                i++;
                j++;
            }
            else{
                if(j == 0){
                    i++;
                }
                else{
                    j = lps[j - 1];
                }
            }
        }

        if(j < m) return -1;
        else return i - m;
    }
};