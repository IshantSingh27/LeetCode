class Solution {
public:
    void sol(int ind , string& temp , vector<string>& ans , string& s , vector<string>& mp){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        } 

        for(int i=0 ; i<mp[s[ind] - '0'].size() ; i++){
            temp.push_back(mp[s[ind] - '0'][i]);
            sol(ind + 1 , temp , ans , s , mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        vector<string> mp = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        string temp;
        vector<string> ans;
        sol(0 , temp , ans , s , mp);
        return ans;
    }
};