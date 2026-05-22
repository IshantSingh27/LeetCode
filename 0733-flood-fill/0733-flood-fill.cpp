class Solution {
public:
    void dfs(int row , int col , int old , int color , vector<vector<int>>& arr , int n , int m){
        arr[row][col] = color;

        vector<int> drow = {0 , 1 , 0 , -1};
        vector<int> dcol = {-1 , 0 , 1 , 0};

        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol] == old){
                dfs(nrow , ncol , old , color , arr , n , m);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int n = arr.size() , m = arr[0].size() , old = arr[sr][sc];
        if(old == color) return arr;
        
        dfs(sr , sc , old , color , arr , n , m);

        return arr;
    }
};