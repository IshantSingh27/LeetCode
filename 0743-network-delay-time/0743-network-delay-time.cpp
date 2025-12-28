class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        pq.push({0 , k});
        vector<int> dist(n + 1 , 1e9);
        dist[k] = 0;
        int ans = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(wt > dist[node]) continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;

                if(wt + adjwt < dist[adjnode]){
                    dist[adjnode] = wt + adjwt;
                    pq.push({dist[adjnode] , adjnode});
                }
            }
        }

        for(int i=1 ; i<=n ; i++){
            if(dist[i] == 1e9) return -1;

            ans = max(ans , dist[i]);
        }
        return ans;
    }
};