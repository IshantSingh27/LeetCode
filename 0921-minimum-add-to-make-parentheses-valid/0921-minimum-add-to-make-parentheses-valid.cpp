class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size() , ans = 0 , i = 0;
        while(i < n){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
            i++;
        }
        return ans + st.size();
    }
};