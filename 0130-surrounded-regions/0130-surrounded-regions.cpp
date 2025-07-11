class Solution {
public:
    void dfs(int row , int col , vector<vector<char>>& arr , vector<vector<int>>& vis){
        int n = arr.size() , m = arr[0].size();
        vis[row][col] = 1;

        vector<int> drow = {-1 , 0 , 1 , 0};
        vector<int> dcol = {0 , 1 , 0 , -1};

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol] == 'O'){
                dfs(nrow , ncol , arr , vis);
            }
        }
    }

    void solve(vector<vector<char>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i=0 ; i<m ; i++){
            if(!vis[0][i] && arr[0][i] == 'O'){
                dfs(0 , i , arr , vis);
            }
        }
        for(int i=0 ; i<m ; i++){
            if(!vis[n-1][i] && arr[n-1][i] == 'O'){
                dfs(n-1 , i , arr , vis);
            }
        }
        for(int i=0 ; i<n ; i++){
            if(!vis[i][0] && arr[i][0] == 'O'){
                dfs(i , 0 , arr , vis);
            }
        }
        for(int i=0 ; i<n ; i++){
            if(!vis[i][m-1] && arr[i][m-1] == 'O'){
                dfs(i , m-1 , arr , vis);
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j]){
                    arr[i][j] = 'X';
                }
            }
        }
    }
};