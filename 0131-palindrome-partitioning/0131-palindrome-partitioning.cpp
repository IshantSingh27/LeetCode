class Solution {
public:
    bool chk(int i , int j , string s){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void sol(int i , string s , vector<string>& temp , vector<vector<string>>& ans){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int j=i ; j<s.size() ; j++){
            if(chk(i , j , s)){
                temp.push_back(s.substr(i , j - i + 1));
                sol(j + 1 , s , temp , ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        sol(0 , s , temp , ans);

        return ans;
    }
};