class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] != ' ' || (!ans.empty() && ans.back() != ' ')){
                ans += s[i];
            }
        }
        if(ans.back() == ' ') ans.pop_back();

        reverse(ans.begin() , ans.end());

        int start = 0;
        for(int i=0 ; i<=ans.size() ; i++){
            if(i == ans.size() || ans[i] == ' '){
                reverse(ans.begin() + start , ans.begin() + i);
                start = i + 1;
            }
        }

        return ans;
    }
};