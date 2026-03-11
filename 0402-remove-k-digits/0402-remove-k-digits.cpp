class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        int n = s.size();

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && k > 0 && st.top() - '0' > s[i] - '0'){
                st.pop();
                k--;
            }

            st.push(s[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";
        string ans;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        while(ans.size() > 0 && ans.back() == '0'){
            ans.pop_back();
        }

        if(ans.empty()) return "0";

        reverse(ans.begin() , ans.end());
        return ans;
    }
};