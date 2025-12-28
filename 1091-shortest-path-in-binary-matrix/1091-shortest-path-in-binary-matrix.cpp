class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        if(arr[0][0] != 0 || arr[n - 1][n - 1] != 0) return -1;
        if(0 == n - 1) return 1;

        vector<vector<int>> dist(n , vector<int>(n , 1e9));
        queue<pair<int , pair<int , int>>> q;
        q.push({1 , {0 , 0}});
        vector<int> drow = {1 , 0 , -1 , 0 , 1 , 1 , -1 , -1};
        vector<int> dcol = {0 , -1 , 0 , 1 , 1 , -1 , 1 , -1};

        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int step = q.front().first;
            q.pop();

            for(int i=0 ; i<8 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && arr[nrow][ncol] == 0 &&
                step + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = step + 1;
                    q.push({step + 1 , {nrow , ncol}});
                }
            }
        }

        if(dist[n - 1][n - 1] == 1e9) return -1;
        return dist[n - 1][n - 1];
    }
};