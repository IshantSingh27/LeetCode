class Solution {
public:
    void solve(int n , int open , string s , vector<string>& ans){
        if(n == 0){
            while(open != 0){
                s += ")";
                open--;
            }
            ans.push_back(s);
            return;
        }

        solve(n - 1 , open + 1 , s + "(" , ans);
        if(open > 0){
            solve(n , open - 1 , s + ")" , ans);
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;

        solve(n , 0 , s , ans);

        return ans;
    }
};