class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string , int> mp;
        vector<string> ans;
        string cur = "";

        for(char it : s){
            cur += it;
            if(mp.find(cur) != mp.end()) continue;
            mp[cur]++;
            ans.push_back(cur);
            cur = "";
        }

        return ans;
    }
};