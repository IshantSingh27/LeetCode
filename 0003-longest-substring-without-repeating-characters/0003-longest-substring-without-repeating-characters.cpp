class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()  == 0) return 0;
        int n = s.length();
        map<char , int> mp;
        for(char ch='a' ; ch <= 'z' ; ch++){
            mp[ch] = -1;
        }
        int l = 0 , r = 0 , maxlen = 1;
        while(r < n){
            if(mp[ s[r] ] != -1){
                if(l <= mp[ s[r] ]){
                    l = mp[ s[r] ] + 1;
                }
            }
            maxlen = max(maxlen , r - l + 1);
            mp[ s[r] ] = r;
            r++;
        }
        return maxlen;
    }
};