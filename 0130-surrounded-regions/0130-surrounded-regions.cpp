class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>& vis , vector<vector<char>>& arr){
        int n = arr.size() , m = arr[0].size();
        vis[row][col] = 1;

        vector<int> drow = {-1 , 0 , 1 , 0};
        vector<int> dcol = {0 , 1 , 0 , -1};

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol] == 'O'){
                dfs(nrow , ncol , vis , arr);
            }
        }
    }
 
    void solve(vector<vector<char>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(!vis[i][j] && arr[i][j] == 'O'){
                        dfs(i , j , vis , arr);
                    }
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 'O' && !vis[i][j]){
                    arr[i][j] = 'X';
                }
            }
        }
    }
};