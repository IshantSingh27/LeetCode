class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> dist(n , vector<int>(n , 1e9));
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0 ; i<n ; i++) dist[i][i] = 0;
        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = -1;
        int city = n;
        for(int i=0 ; i<n ; i++){
            int cnt = 0;
            for(int j=0 ; j<n ; j++){
                if(dist[i][j] <= k){
                    cnt++;
                }
            }
            if(cnt <= city){
                city = cnt;
                ans = i;
            }
        }
        return ans;
    }
};