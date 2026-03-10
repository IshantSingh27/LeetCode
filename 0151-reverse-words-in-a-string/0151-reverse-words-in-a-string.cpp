class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp , ans;
        reverse(s.begin() , s.end());

        for(int i=0 ; i<n ; i++){
            if(s[i] == ' ' && temp.size() == 0) continue;
            else if(s[i] == ' '){
                reverse(temp.begin() , temp.end());
                ans += temp + ' ';
                temp = "";
            }
            else{
                temp += s[i];
            }
        }

        if(temp.size() != 0){
            reverse(temp.begin() , temp.end());
            ans += temp + ' ';
        }
        ans.pop_back();
        return ans;
    }
};