class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<vector<char>> arr;
        stack<char> st;
        
        vector<char> temp;
        for(int i=0 ; i<s.size() ; i++){
            temp.push_back(s[i]);
            if(s[i] == '(') st.push(s[i]);
            else st.pop();

            if(st.empty()){
                arr.push_back(temp);
                temp = {};
            }
        }

        string ans = "";
        for(auto it : arr){
            for(int i=1 ; i<=it.size() - 2 ; i++){
                ans += it[i];
            }
        }

        return ans;
    }
};