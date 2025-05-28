class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        queue<pair<int , pair<int , int>>> q;
        q.push({0 , {src , 0}});
        vector<int> dist(n , 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto fr = q.front();
            int stop = fr.first;
            int node = fr.second.first;
            int cost = fr.second.second;
            q.pop();

            if(stop > k) continue;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjcost = it.second;
                if(cost + adjcost < dist[adjnode]){
                    dist[adjnode] = cost + adjcost;
                    q.push({stop + 1 , {adjnode , dist[adjnode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};