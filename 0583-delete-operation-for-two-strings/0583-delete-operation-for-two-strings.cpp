class Solution {
public:
    int solve(string s1 , string s2){
        int n = s1.size() , m = s2.size();
        vector<int> prev(m + 1 , 0) , cur(m + 1 , 0);

        for(int ind1 = 1 ; ind1 <= n ; ind1++){
            for(int ind2 = 1 ; ind2 <= m ; ind2++){
                if(s1[ind1 - 1] == s2[ind2 - 1]){
                    cur[ind2] = 1 + prev[ind2 - 1];
                }
                else{
                    cur[ind2] = 0 + max(cur[ind2 - 1] , prev[ind2]);
                }
            }
            prev = cur;
        }

        return prev[m];
    }

    int minDistance(string s1, string s2) {
        return s1.size() + s2.size() - (2 * solve(s1 , s2));
    }
};