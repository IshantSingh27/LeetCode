class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<long long , long long>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> ,
        greater<pair<long long , long long>>> pq;
        pq.push({0 , 0});
        vector<long long> dist(n , 1e18) , ways(n , 0);
        dist[0] = 0;
        ways[0] = 1;
        long long ans = 0 , mod = 1e9 + 7;

        while(!pq.empty()){
            long long node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();

            if(wt > dist[node]) continue;

            for(auto it : adj[node]){
                long long adjnode = it.first;
                long long adjwt = it.second;

                if(wt + adjwt < dist[adjnode]){
                    dist[adjnode] = wt + adjwt;
                    pq.push({dist[adjnode] , adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(wt + adjwt == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod; 
                }
            }
        }

        return ways[n - 1] % mod;
    }
};