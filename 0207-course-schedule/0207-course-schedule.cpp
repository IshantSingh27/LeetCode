class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> indeg(v , 0);
        for(auto it : adj){
            for(auto it1 : it){
                indeg[it1]++;
            }
        }
        
        queue<int> q;
        for(int i=0 ; i<v ; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indeg[it]--;
                
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        if(ans.size() != v) return false;
        else return true;
    }
};