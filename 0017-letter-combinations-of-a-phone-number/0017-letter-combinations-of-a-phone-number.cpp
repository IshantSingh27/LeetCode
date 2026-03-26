class Solution {
public:
    void solve(int ind , vector<string>& mp , string temp , string s ,  vector<string>& ans){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0 ; i<mp[s[ind] - '0'].size() ; i++){
            solve(ind + 1 , mp , temp + mp[s[ind] - '0'][i] , s , ans);
        }
    }

    vector<string> letterCombinations(string s) {
        vector<string> mp = {"" , "" , "abc" ,  "def" , "ghi" ,
        "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

        vector<string> ans;
        string temp;

        solve(0 , mp , temp , s , ans);

        return ans;
    }
};