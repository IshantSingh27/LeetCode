class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size() , ans = 0;

        if(n == 1){
            if(s1[0] != s2[0]){
                if(s1[0] == '1') return -1;
                else return 1;
            }
            else return 0;
        }

        for(int i=0 ; i<n - 1 ; i++){
            if(s1[i] == s2[i]) continue;
            else{
                if(s1[i] == '1'){
                    if(s1[i + 1] == '1'){
                        ans++;
                        s1[i + 1] = '0';
                    }
                    else{
                        ans += 2;
                    }
                }
                else{
                    ans++;
                }
            }
        }

        if(s1[n - 1] == s2[n - 1]) return ans;
        else{
            if(s1[n - 1] == '0') return ans + 1;
            else{
                return ans + 2;
            }
        }
    }
};