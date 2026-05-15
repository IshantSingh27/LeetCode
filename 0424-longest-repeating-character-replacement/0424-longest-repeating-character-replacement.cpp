class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int , int> mp;
        int maxfreq = 0 , l = 0 , ans = 0;

        for(int i=0 ; i<s.size() ; i++){
            mp[s[i] - 'A']++;
            maxfreq = max(maxfreq , mp[s[i] - 'A']);

            if((i - l + 1) - maxfreq > k){
                mp[s[l] - 'A']--;
                l++;
            }
            else{
                ans = max(ans , i - l + 1);
            }
        }

        return ans;
    }
};