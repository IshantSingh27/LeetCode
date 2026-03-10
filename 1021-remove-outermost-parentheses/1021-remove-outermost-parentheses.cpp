class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int n = s.size() , cnt = 0;

        for(int i=0 ; i<n ; i++){
            if(s[i] == '('){
                if(cnt != 0){
                    ans += s[i];
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt != 0) ans += ')';
            }
            // cout<<"cnt : "<<cnt<<endl;
        }

        return ans;
    }
};