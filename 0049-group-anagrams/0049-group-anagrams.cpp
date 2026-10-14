class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string , vector<string>> mp;
        for(auto it : arr){
            string s = it;
            sort(s.begin() , s.end());
            mp[s].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};