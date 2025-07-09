class Solution {
public:
    void solve(int row, int col, vector<vector<int>>& arr, vector<vector<int>>& ans, int color, int newcol){
        ans[row][col] = newcol;
        vector<int> drow = {-1 , 0 , 1 , 0};
        vector<int> dcol = {0 , 1 , 0 , -1};
        int n = arr.size() , m = arr[0].size();

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol] == color && ans[nrow][ncol] != newcol){
                solve(nrow , ncol , arr , ans , color , newcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int newcol) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> ans = arr;
        int color = arr[sr][sc];

        solve(sr , sc , arr , ans , color , newcol);

        return ans;
    }
};