class Solution {
public:
    void sol(int n , int one , string& s , vector<string>& ans){
        if(n == 0){
            string t = s;
            while(one > 0){
                t.push_back(')');
                one--;
            }
            ans.push_back(t);
            return;
        }

        s.push_back('(');
        sol(n - 1 , one + 1 , s , ans);
        s.pop_back();

        if(one > 0){
            s.push_back(')');
            sol(n , one - 1 , s , ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        sol(n , 0 , s , ans);
        return ans;
    }
};