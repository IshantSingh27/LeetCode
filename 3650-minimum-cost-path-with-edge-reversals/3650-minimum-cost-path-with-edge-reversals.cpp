class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , 2 * it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0 , 0});

        vector<int> dist(n , 1e9);
        dist[0] = 0;

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(wt > dist[node]) continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;

                if(wt + adjwt < dist[adjnode]){
                    dist[adjnode] = wt + adjwt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        return dist[n - 1] == 1e9 ? -1 : dist[n - 1];
    }
};
