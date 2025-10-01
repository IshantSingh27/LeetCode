class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '('){
                if(depth == 0) depth++;
                else{
                    depth++;
                    ans += s[i];
                }
            }
            else{
                depth--;
                if(depth == 0) continue;
                else{
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};