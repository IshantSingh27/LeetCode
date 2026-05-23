class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& arr) {
        int v = arr.size();
        vector<vector<int>> adj(v);
        for(int i=0 ; i<v ; i++){
            for(auto it : arr[i]){
                adj[it].push_back(i);
            }
        }
        vector<int> indeg(v , 0) , ans;
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
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        sort(ans.begin() , ans.end());
        return ans;
    }
};