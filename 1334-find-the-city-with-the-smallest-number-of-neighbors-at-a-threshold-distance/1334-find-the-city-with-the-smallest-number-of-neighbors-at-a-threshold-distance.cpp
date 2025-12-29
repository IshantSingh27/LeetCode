class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int cap) {
        vector<vector<int>> dist(n , vector<int>(n , 1e9));
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9 && dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int ans = 1e9 , res = 0;
        for(int i=0 ; i<n ; i++){
            int cur = 0;
            for(int j=0 ; j<n ; j++){
                if(i == j) continue;
                if(dist[i][j] <= cap) cur++;
            }

            if(cur <= ans){
                ans = cur;
                res = i;
            }
        }

        return res;
    }
};