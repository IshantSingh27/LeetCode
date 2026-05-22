class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size() , cnt = 0 , ans = 0 , t = 0;
        queue<pair<pair<int , int> , int>> q;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        vector<int> drow = {0 , 1 , 0 , -1};
        vector<int> dcol = {-1 , 0 , 1 , 0};

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 2){
                    q.push({{i , j} , 0});
                    vis[i][j] = 1;
                }
                else if(arr[i][j] == 1) cnt++;
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            t = time;
    
            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
    
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && arr[nrow][ncol]==1){
                    q.push({{nrow , ncol} , time + 1});
                    vis[nrow][ncol] = 1;
                    ans++;
                }
            }
        }

        if(ans != cnt){
            return -1;
        }
        else{
            return t;
        }
    }
};