class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>& vis , vector<vector<char>>& arr){
        int n = arr.size() , m = arr[0].size();
        vector<int> drow = {0 , 1 , 0 , -1};
        vector<int> dcol = {-1 , 0 , 1 , 0};
        vis[row][col] = 1;

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol] == '1'){
                dfs(nrow , ncol , vis , arr);
            }
        }
    }
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size() , m = arr[0].size() , cnt = 0;;
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == '1' && !vis[i][j]){
                    dfs(i , j , vis , arr);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};