class Solution {
public:
    bool checkValidString(string s) {
        int maxi = 0 , mini = 0 , n = s.size();
        for(int i=0 ; i<n ; i++){
            if(s[i] == '('){
                maxi++;
                mini++;
            }
            else if(s[i] == ')'){
                maxi--;
                mini--;
            }
            else{
                maxi++;
                mini--;
            }
            if(maxi < 0) return false;
            if(mini < 0) mini = 0;
        }
        return mini == 0;

    }
};