class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> mp;
        int n = s.size() , i = 0 , j = 0 , ans = 0;
        while(i < n){
            if(mp[s[i]] == 0) mp[s[i]]++;
            else{
                while(j < i){
                    mp[s[j]]--;
                    j++;
                    if(mp[s[i]] == 0) break;
                }
                mp[s[i]]++;
            }
            ans = max(ans , i - j + 1);
            i++;
        }

        return ans;
    }
};