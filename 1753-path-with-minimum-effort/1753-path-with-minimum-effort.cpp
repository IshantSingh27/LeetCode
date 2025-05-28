class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& high) {
        int n = high.size();
        int m = high[0].size();
        vector<int> drow = {0 , -1 , 0 , 1};
        vector<int> dcol = {1 , 0 , -1 , 0};
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> ,
        greater<pair<int , pair<int , int>>>> pq;

        vector<vector<int>> dist(n , vector<int>(m , 1e9));
        dist[0][0] = 0;
        pq.push({0 , {0 , 0}});

        while(!pq.empty()){
            auto it = pq.top();
            int row = it.second.first;
            int col = it.second.second;
            int ht = it.first;
            pq.pop();

            if(row == n-1 && col == m-1) return ht;

            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int nhigh = max(abs(high[nrow][ncol] - high[row][col]) , ht);

                    if(nhigh < dist[nrow][ncol]){
                        dist[nrow][ncol] = nhigh;
                        pq.push({nhigh , {nrow , ncol}});
                    }
                }
            }
        }
        return 0;
    }
};