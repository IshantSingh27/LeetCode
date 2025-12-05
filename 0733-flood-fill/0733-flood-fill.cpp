class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>& arr , vector<vector<int>>& vis , int color , int old){
        int n = arr.size() , m = arr[0].size();
        vis[row][col] = color;

        vector<int> drow = {-1, 0 , 1 , 0};
        vector<int> dcol = {0, 1 , 0 , -1};

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol] == old && vis[nrow][ncol] != color){
                dfs(nrow , ncol , arr , vis , color , old);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int n = arr.size() , m = arr[0].size() , old = arr[sr][sc];
        vector<vector<int>> vis(n , vector<int>(m , 0));

        dfs(sr , sc , arr , vis , color , old);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] == 0){
                    vis[i][j] = arr[i][j];
                }
            }
        }

        return vis;
    }
};