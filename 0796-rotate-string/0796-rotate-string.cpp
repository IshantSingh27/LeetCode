class Solution {
public:
    bool rotateString(string s, string g) {
        int n = s.size();
        if(g.size() != n) return false;

        for(int i=0 ; i<n ; i++){
            if(s[0] == g[i]){
                bool chk = true;
                for(int j=1 ; j<n ; j++){
                    if(s[j] != g[(i + j) % n]) chk = false;
                }
                if(chk) return true;
            }
        }

        return false;
    }
};