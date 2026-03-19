class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char> st;

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && k > 0 && st.top() - '0' > s[i] - '0'){
                st.pop();
                k--;
            }

            st.push(s[i]);
        }

        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin() , ans.end());

        if(ans.empty()) return "0";
        else return ans;
    }
};