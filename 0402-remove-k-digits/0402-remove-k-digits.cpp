class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char> st;

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && st.top() > s[i] && k > 0){
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
            ans.push_back(st.top());
            st.pop();
        }
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin() , ans.end());
        return ans;
    }
};