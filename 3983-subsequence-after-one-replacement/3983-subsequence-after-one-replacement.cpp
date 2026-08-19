class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size() , m = t.size();
        vector<int> pre(n , m) , suf(n , -1);

        int p = 0;
        for(int i=0 ; i<n ; i++){
            while(p < m && t[p] != s[i]) p++;

            if(p == m){
                break;
            }

            pre[i] = p++;
        }

        if (pre[n - 1] != m) return true;

        p = m - 1;
        for(int i=n - 1 ; i>=0 ; i--){
            while(p >= 0 && t[p] != s[i]) p--;

            if(p < 0) break;

            suf[i] = p--;
        }

        for(int i=0 ; i<n ; i++){
            int left , right;
            if(i==0) left = -1;
            else left = pre[i - 1];
            if(i == n - 1) right = m;
            else right = suf[i + 1];

            if(left != m && right != -1){
                if(left + 1 < right) return true;
            }
        }
        return false;
    }
};