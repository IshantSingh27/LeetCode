class Solution {
public:
    string largestOddNumber(string s) {
        int ans = -1;
        for(int i=s.size() - 1 ; i>=0 ; i--){
            if(s[i] % 2 != 0){
                ans = i;
                break;
            }
        }

        if(ans == -1) return "";
        else{
            string res = "";
            for(int i=0 ; i<=ans ;  i++){
                res += s[i];
            }
            return res;
        }
    }
};