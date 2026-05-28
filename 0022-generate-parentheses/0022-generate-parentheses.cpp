class Solution {
public:
    void sol(int n , int open , string& s , vector<string>& ans){
        if(n == 0){
            string temp = s;
            while(open != 0){
                temp += ')';
                open--;
            }
            ans.push_back(temp);
            return;
        }

        s.push_back('(');
        sol(n - 1 , open + 1 , s , ans);
        s.pop_back();
        if(open > 0){
            s.push_back(')');
            sol(n , open - 1 , s , ans);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        sol(n , 0 , s , ans);
        return ans;
    }
};