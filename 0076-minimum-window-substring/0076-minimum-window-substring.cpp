class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size() , cnt = 0 , ans = 1e9 , l = 0 , sind = -1;
        unordered_map<int , int> mp;
        
        for(int i=0 ; i<m ; i++){
            mp[t[i]]++;
        }

        for(int i=0 ; i<n ; i++){
            if(mp[s[i]] > 0) cnt++;
            mp[s[i]]--;

            while(cnt == m){
                if(ans > i - l + 1){
                    ans = i - l + 1;
                    sind = l;
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