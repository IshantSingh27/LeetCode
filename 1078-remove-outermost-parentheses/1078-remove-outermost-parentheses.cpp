class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        vector<char> temp;

        for(int i=0 ; i<s.size() ; i++){
            temp.push_back(s[i]);
            if(s[i] == '(') st.push(s[i]);
            else st.pop();

            if(st.empty()){
                for(int i=1 ; i<=temp.size() - 2 ; i++){
                    ans += temp[i];
                }
                temp = {};
            }
        }

        return ans;
    }
};