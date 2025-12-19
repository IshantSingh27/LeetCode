class Solution {
public:
    bool palin(int s , int e , string arr){
        while(s <= e){
            if(arr[s++] != arr[e--]) return false;
        }

        return true;
    }

    void sol(int ind  , string s , vector<string>& temp , vector<vector<string>>& ans){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<s.size() ; i++){
            if(palin(ind , i , s)){
                temp.push_back(s.substr(ind , i - ind + 1));
                sol(i + 1 , s , temp , ans);
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