class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> mp;
        int n = s.size() , m = t.size();
        if(n != m) return false;

        for(int i=0 ; i<n ; i++){
            mp[s[i]]++;
        }

        for(int i=0 ; i<m ; i++){
            mp[t[i]]--;
            if(mp[t[i]] == 0) mp.erase(t[i]);
        }

        if(mp.size() != 0) return false;
        else return true;
    }
};