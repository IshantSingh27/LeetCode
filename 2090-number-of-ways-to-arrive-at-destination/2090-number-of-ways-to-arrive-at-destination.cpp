class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long , long long>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        vector<long long> time(n , 1e18) , ways(n , 0);
        time[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> ,
        greater<pair<long long , long long>>> pq;
        pq.push({0 , 0});
        long long mod = 1e9 + 7;
        while(!pq.empty()){
            long long wt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                long long adjnode = it.first;
                long long adjwt = it.second;
                if((wt + adjwt) < time[adjnode]){
                    time[adjnode] = (wt + adjwt);
                    ways[adjnode] = ways[node];
                    pq.push({time[adjnode] , adjnode});
                }
                else if((wt + adjwt) == time[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};