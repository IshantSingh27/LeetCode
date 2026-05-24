class Solution {
public:
    int networkDelayTime(vector<vector<int>>& arr, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);
        for(auto it : arr){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        pq.push({0 , k});
        vector<int> dist(n + 1 , 1e9);
        dist[k] = 0;

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;

                if(adjwt + wt < dist[adjnode]){
                    dist[adjnode] = adjwt + wt;
                    pq.push({dist[adjnode] , adjnode});
                }
            }
        }
        int ans = -1;
        for(int i=1 ; i<=n ; i++){
            if(dist[i] == 1e9) return -1;
            else ans = max(ans , dist[i]);
        }
        return ans;
    }
};