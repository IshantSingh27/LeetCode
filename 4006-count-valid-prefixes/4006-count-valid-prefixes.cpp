class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0 = 0 , cnt1 = 0 , n = s.size() , ans = 0;
        for(int i=0 ; i<n ; i++){
            if(s[i] == '0') cnt0++;
            else if(s[i] == '1') cnt1++;

            if(cnt0 == cnt1 || abs(cnt0 - cnt1) == 1) ans++;
        }
        return ans;
    }
};