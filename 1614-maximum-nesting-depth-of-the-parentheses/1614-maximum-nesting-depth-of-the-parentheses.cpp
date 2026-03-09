class Solution {
public:
    int maxDepth(string s) {
        int ans = 0 , depth = 0;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '('){
                depth++;
            }
            else if(s[i] == ')'){
                depth--;
            }

            ans = max(ans , depth);
        }

        return ans;
    }
};