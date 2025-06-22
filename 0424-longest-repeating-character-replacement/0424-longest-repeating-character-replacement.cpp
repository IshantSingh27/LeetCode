class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size() , maxlen = 0 , maxfreq = 0 , l = 0 , r = 0;
        vector<int> mp(26 , 0);
        while(r < n){
            mp[s[r] - 'A']++;
            maxfreq = max(maxfreq , mp[s[r] - 'A']);
            if( (r - l + 1) - maxfreq > k){
                mp[s[l] - 'A']--;
                for(int i=0 ; i<26 ; i++) maxfreq = max(maxfreq , mp[i]);
                l++;
            }
            else{
                maxlen = max(maxlen , r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};