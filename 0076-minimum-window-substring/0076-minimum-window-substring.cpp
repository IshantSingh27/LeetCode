class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> mp;
        int n = s.size() , m = t.size() , ans = 1e9 , l = 0 , sind = -1 , cnt = 0;

        for(int i=0 ; i<m ; i++){
            mp[t[i]]++;
        }

        for(int i=0 ; i<n ; i++){
            if(mp[s[i]] > 0) cnt++;
            mp[s[i]]--;

            while(cnt == m){
                if(ans > i - l + 1){
                    sind = l;
                    ans = i - l + 1;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;

                l++;
            }
        }

        if(sind == -1) return "";
        else return s.substr(sind , ans);
    }
};