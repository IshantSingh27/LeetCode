class Solution {
public:
    vector<long long> sol(long long src , vector<vector<pair<long long , long long>>>& adj){
        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> , greater<pair<long long , long long>>> pq;
        pq.push({0 , src});
        vector<long long> dist(adj.size() , LLONG_MAX);
        dist[src] = 0;

        while(!pq.empty()){
            long long node = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();

            if(cost > dist[node]) continue;

            for(auto it : adj[node]){
                long long newnode = it.first;
                long long newcost = it.second;
                if(cost + newcost < dist[newnode]){
                    dist[newnode] = cost + newcost;
                    pq.push({dist[newnode] , newnode});
                }
            }
        }

        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long long , long long>>> adj(n) , rev(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            rev[it[1]].push_back({it[0] , it[2]});
        }

        vector<long long> one = sol(src1 , adj);
        vector<long long> two = sol(src2 , adj);
        vector<long long> three = sol(dest , rev);

        long long mini = LLONG_MAX;

        for(long long i=0 ; i<n ; i++){
            if(one[i] == LLONG_MAX || two[i] == LLONG_MAX || three[i] == LLONG_MAX) continue;

            mini = min(mini , one[i] + two[i] + three[i]);
        }

        if(mini == LLONG_MAX) return -1;
        else return mini;
    }
};