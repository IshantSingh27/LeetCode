class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        if(k == 1){
            vector<string> ans(n , string(m , '#'));

            for(int i=0 ; i<m ; i++){
                ans[0][i] = '.';
            }

            for(int i=0 ; i<n ; i++){
                ans[i][m - 1] = '.';
            }

            return ans;
        }

        if(m >= k && n >= 2){
            vector<string> ans(n , string(m , '#'));

            for(int i=0 ; i<m ; i++){
                ans[0][i] = '.';
            }

            for(int i=m - k ; i<m ; i++){
                ans[1][i] = '.';
            }

            for(int i=0 ; i<n ; i++){
                ans[i][m - 1] = '.';
            }

            return ans;
        }

        if(n >= k && m >= 2){
            vector<string> ans(n , string(m , '#'));

            for(int i=0 ; i<m ; i++){
                ans[0][i] = '.';
            }

            for(int i=1 ; i<k ; i++){
                ans[i][m - 2] = '.';
            }

            for(int i=0 ; i<n ; i++){
                ans[i][m - 1] = '.';
            }

            return ans;
        }

        if(n == 3 && m == 3 && k == 4){
            return {
                "..#",
                "...",
                "#.."
            };
        }

        return {};
    }
};