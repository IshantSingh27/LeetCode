class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;
        unordered_map<char , int> mp;
        for(char i='a' ; i<='z' ; i++){
            mp[i] = -1;
        }

        int l = 0 , r = 0 , maxlen = 1;
        while(r < n){
            if(mp[s[r]] != -1){
                l = max(l , mp[s[r]] + 1);
            }
            maxlen = max(maxlen , r  - l + 1);
            // cout<<"len : "<<r - l + 1<<" | ";

            mp[s[r]] = r;
            r++;
            // cout<<"maxlen : "<<maxlen<<endl;
        }

        return maxlen;
    }
};