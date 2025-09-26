class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indeg(n , 0);
        for(int i=0 ; i<n ; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0 ; i<n ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size() == n) return ans;
        else return {};
    }
};