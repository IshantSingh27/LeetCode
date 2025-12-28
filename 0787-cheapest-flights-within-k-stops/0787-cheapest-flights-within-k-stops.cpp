class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> ,
        greater<pair<int , pair<int , int>>>> pq;
        pq.push({0 , {0 , src}});
        vector<int> dist(n , 1e9);

        while(!pq.empty()){
            int node = pq.top().second.second;
            int price = pq.top().second.first;
            int stops = pq.top().first;
            pq.pop();

            if(stops > k || node == dst) continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjprice = it.second;

                if(price + adjprice < dist[adjnode]){
                    dist[adjnode] = price + adjprice;
                    pq.push({stops + 1 , {dist[adjnode] , adjnode}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};