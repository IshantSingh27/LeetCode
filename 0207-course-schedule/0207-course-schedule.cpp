class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indeg(v , 0);
        queue<int> q;
        
        for(int i=0 ; i<v ; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        for(int i=0 ; i<v ; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        for(int i=0 ; i<v ; i++){
            if(indeg[i] != 0) return false;
        }
        return true;
    }
};