class Solution {
public:
    void sol(string s , vector<int>& lps){
        int pre = 0 , suf = 1 , n = s.size();

        while(suf < n){
            if(s[suf] == s[pre]){
                lps[suf] = pre + 1;
                suf++;
                pre++;
            }
            else if(pre == 0){
                suf++;
            }
            else{
                pre = lps[pre - 1];
            }
        }
    }
    int strStr(string s, string pat) {
        int n = s.size() , m = pat.size();
        vector<int> lps(m , 0);
        sol(pat , lps);

        int i = 0 , j = 0;
        while(i < n && j < m){
            if(s[i] == pat[j]){
                i++;
                j++;
            }
            else if(j == 0){
                i++;
            }
            else{
                j = lps[j - 1];
            }
        }

        if(j == m) return i - j;
        else return -1;
    }
};