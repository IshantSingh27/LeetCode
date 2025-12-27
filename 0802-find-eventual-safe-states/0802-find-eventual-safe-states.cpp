class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n , 0);
        for(int i=0 ; i<n ; i++){
            for(auto it : edges[i]){
                adj[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        for(int i=0 ; i<n ; i++){
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

        sort(ans.begin() , ans.end());
        
        return ans;
    }
};