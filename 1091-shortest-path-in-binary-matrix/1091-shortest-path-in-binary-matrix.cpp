class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        if(arr[0][0] == 1) return -1;
        int n = arr.size();
        vector<vector<int>> vis(n , vector<int>(n , 0));
        queue<pair<int , pair<int , int>>> q;
        q.push({1 , {0 , 0}});
        vis[0][0] = 1;
        vector<int> drow = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1};
        vector<int> dcol = {-1 , 0 , 1 , 0 , 1 , -1 , -1 , 1};

        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int step = q.front().first;
            q.pop();
            if(row == n-1 && col == n-1) return step;

            for(int i=0 ; i<8 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && arr[nrow][ncol] == 0){
                    q.push({step + 1 , {nrow , ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return -1;
    }
};