class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size() , cntfresh = 0 , time = 0 , cnt = 0;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        queue<pair<pair<int , int> , int>> q;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({{i , j} , 0});
                }
                else if(arr[i][j] == 1) cntfresh++;
            }
        }

        vector<int> drow = {-1 , 0 , 1 , 0};
        vector<int> dcol = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time , t);

            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
    
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow , ncol} , t + 1});
                    cnt++;
                }
            }
        }

        if(cntfresh != cnt) return -1;
        else return time;
    }
};