class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : arr){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        queue<pair<int , pair<int , int>>> q;
        q.push({0 , {0 , src}});
        vector<int> dist(n , 1e9);

        while(!q.empty()){
            int stops = q.front().first;
            int wt = q.front().second.first;
            int node = q.front().second.second;
            q.pop();

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;

                if(dist[adjnode] > adjwt + wt){
                    dist[adjnode] = adjwt + wt;
                    q.push({stops + 1 , {dist[adjnode] , adjnode}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};