class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size() , cntfresh = 0 , cnt = 0 , ans = 0;
        queue<pair<int , pair<int , int>>> q;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 2){
                    q.push({0 , {i , j}});
                    vis[i][j] = 1;
                }
                else if(arr[i][j] == 1) cntfresh++;
            }
        }

        vector<int> drow = {0 , -1 , 0 , 1};
        vector<int> dcol = {1 , 0 , -1 , 0};

        while(!q.empty()){
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            ans = max(ans , time);

            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({time + 1 , {nrow , ncol}});
                    cnt++;
                }
            }
        }

        if(cnt == cntfresh) return ans;
        else return -1;
    }
};