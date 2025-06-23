class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size() , minlen = 1e9 , l = 0 , r = 0 , cnt = 0 , sind = -1;
        unordered_map<char , int> mp;
        for(int i=0 ; i<m ; i++) mp[t[i]]++;
        while(r < n){
            if(mp[s[r]] > 0) cnt++;
            mp[s[r]]--;
            while(cnt == m){
                if(r - l + 1 < minlen){
                    minlen = r - l + 1;
                    sind = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(sind == -1) return "";
        else return s.substr(sind , minlen);
    }
};