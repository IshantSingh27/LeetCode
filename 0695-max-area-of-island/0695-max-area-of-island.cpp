class Solution {
public:
    void dfs(int row , int col , int& cur , vector<vector<int>>& vis , vector<vector<int>>& arr){
        vis[row][col] = 1;
        cur++;

        int n = arr.size() , m = arr[0].size();
        vector<int> drow = {1 , 0 , -1 , 0};
        vector<int> dcol = {0 , -1 , 0 , 1};

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol] == 1){
                dfs(nrow , ncol , cur , vis , arr);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size() , ans = 0;
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && arr[i][j] == 1){
                    int cur = 0;
                    dfs(i , j , cur , vis , arr);
                    ans = max(ans , cur);
                }
            }
        }

        return ans;
    }
};