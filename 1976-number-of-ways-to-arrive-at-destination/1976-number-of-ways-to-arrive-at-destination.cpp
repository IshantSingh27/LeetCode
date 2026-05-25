class Solution {
public:
    int countPaths(int n, vector<vector<int>>& arr) {
        long long mod = 1e9 + 7;
        vector<vector<pair<long long , long long>>> adj(n);
        for(auto it : arr){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> , greater<pair<long long , long long>>> pq;
        vector<long long> dist(n , 1e18);
        vector<long long> ways(n , 0);
        pq.push({0 , 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                long long adjnode = it.first;
                long long adjwt = it.second;
                if(adjwt + wt < dist[adjnode]){
                    dist[adjnode] = wt + adjwt;
                    pq.push({dist[adjnode] , adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(adjwt + wt == dist[adjnode]){
                    ways[adjnode] = (ways[node] + ways[adjnode]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};