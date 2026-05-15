class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3 , -1);
        int cnt = 0;

        for(int i=0 ; i<s.size() ; i++){
            last[s[i] - 'a'] = i;

            if(last[0] != -1 && last[1] != -1 && last[2] != -1){
                cnt += min(last[0] , min(last[1] , last[2])) + 1;
            }
        }

        return cnt;
    }
};