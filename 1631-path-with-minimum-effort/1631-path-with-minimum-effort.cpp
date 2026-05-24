class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> dist(n , vector<int>(m , 1e9));
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> ,
        greater<pair<int , pair<int , int>>>> pq;
        pq.push({0 , {0 , 0}});
        dist[0][0] = 0;
        vector<int> drow = {0 , 1 , 0 , -1};
        vector<int> dcol = {-1 , 0 , 1 , 0};

        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int ndif = abs(arr[row][col] - arr[nrow][ncol]);
                    int ndis = max(ndif , diff);
                    if(dist[nrow][ncol] > ndis){
                        dist[nrow][ncol] = ndis;
                        pq.push({ndis , {nrow , ncol}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};