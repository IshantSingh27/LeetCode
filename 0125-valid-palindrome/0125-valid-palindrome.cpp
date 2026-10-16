class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string ans;

        for(int i=0 ; i<n ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + 32;
            }

            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                ans += s[i];
            }
        }

        int i = 0 , j = ans.size() - 1;
        while(i <= j){
            if(ans[i] != ans[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};