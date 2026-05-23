class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        if(arr[0][0] == 1) return -1;
        int n = arr.size();
        vector<vector<int>> dist(n , vector<int>(n , 1e9));
        queue<pair<int , pair<int , int>>> q;
        q.push({1 , {0 , 0}});
        dist[0][0] = 1;
        vector<int> drow = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1};
        vector<int> dcol = {-1 , 0 , 1 , 0 , 1 , -1 , -1 , 1};

        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int step = q.front().first;
            q.pop();

            for(int i=0 ; i<8 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && arr[nrow][ncol] == 0 
                && dist[nrow][ncol] > step + 1){
                    if(nrow == n-1 && ncol == n - 1) return step + 1;
                    q.push({step + 1 , {nrow , ncol}});
                    dist[nrow][ncol] = step + 1;
                }
            }
        }
        if(dist[n-1][n-1] != 1e9) return dist[n-1][n-1];
        return -1;
    }
};