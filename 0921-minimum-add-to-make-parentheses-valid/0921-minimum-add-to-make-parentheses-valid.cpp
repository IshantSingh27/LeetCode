class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0 , n = s.size() , ans = 0;

        for(int i=0 ; i<n ; i++){
            if(s[i] == '(') open++;
            else open--;

            if(open < 0){
                ans++;
                open = 0;
            }
        }

        ans += open;

        return ans;
    }
};