class Solution {
public:
    bool sol(int row , int col , int ind ,string s , vector<vector<char>>& arr , vector<vector<int>>& vis){
        if(ind == s.size()) return true;

        vis[row][col] = 1;
        int n = arr.size() , m = arr[0].size();
        vector<int> drow = {0 , 1,  0 , -1};
        vector<int> dcol = {-1 , 0 , 1 , 0};

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol] == s[ind] && !vis[nrow][ncol]){
                if(sol(nrow , ncol , ind + 1 , s , arr , vis)) return true;
            }
        }

        vis[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& arr, string s) {
        string temp;
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == s[0]){
                    if(sol(i , j , 1 , s , arr , vis)) return true;
                }
            }
        }

        return false;
    }
};