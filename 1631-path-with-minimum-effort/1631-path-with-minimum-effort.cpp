class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> dist(n , vector<int>(m , 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> ,
        greater<pair<int , pair<int , int>>>> pq;
        pq.push({0 , {0 , 0}});
        vector<int> drow = {1 , 0 , -1 , 0};
        vector<int> dcol = {0 , -1 , 0 , 1};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int cost = pq.top().first;
            pq.pop();

            if(row == n - 1 && col == m - 1) return dist[n - 1][m - 1];

            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int ncost = max(abs(arr[nrow][ncol] - arr[row][col]) , cost);

                    if(ncost < dist[nrow][ncol]){
                        dist[nrow][ncol] = ncost;
                        pq.push({dist[nrow][ncol] , {nrow , ncol}});
                    }
                }
            }
        }

        return -1;
    }
};