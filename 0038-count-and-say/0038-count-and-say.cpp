class Solution {
public:
    void sol(int n , string& ans){
        if(n == 0) return;

        sol(n - 1 , ans);

        if(n == 1){
            ans += "1";
        }
        else{
            string temp;
            int cnt = 1;
            for(int i=0 ; i<ans.size() - 1 ; i++){
                if(ans[i] == ans[i + 1]){
                    cnt++;
                }
                else{
                    temp += to_string(cnt);;
                    temp += ans[i];
                    cnt = 1;
                }
            }
            temp += to_string(cnt);;
            temp += ans.back();
            ans = temp;
        }
    }
    string countAndSay(int n) {
        string ans;
        sol(n , ans);
        return ans;
    }
};