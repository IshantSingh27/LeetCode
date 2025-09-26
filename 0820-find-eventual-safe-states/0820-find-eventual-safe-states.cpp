// class Solution {
// public:
//     bool dfs(vector<vector<int>>& arr , vector<int>& vis , vector<int>& path , int node , 
//     vector<int>& check){
//         vis[node] = 1;
//         path[node] = 1;
        
//         for(auto it : arr[node]){
//             if(!vis[it]){
//                 if(dfs(arr , vis , path , it , check) == true){
//                     return true;
//                 }
//             }
//             else if(path[it]){
//                 return true;
//             }
//         }
        
//         check[node] = 1;
//         path[node] = 0;
//         return false;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& arr) {
//         int n = arr.size();
//         vector<int> vis(n+1 , 0);
//         vector<int> path(n+1 , 0);
//         vector<int> check(n , 0);
        
//         for(int i=0 ; i<n ; i++){
//             if(!vis[i]){
//                 dfs(arr , vis , path , i , check);
//             }
//         }
        
//         vector<int> ans;
//         for(int i=0 ; i<n ; i++){
//             if(check[i] == 1){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n , 0);
        // reverse as outgoing edges.
        for(int i=0 ; i<n ; i++){
            for(auto it : edges[i]){
                adj[it].push_back(i);
                indeg[i]++;
            }
        }

        // vector<int> indeg(n , 0);
        // for(int i=0 ; i<n ; i++){
        //     for(auto it : adj[i]){
        //         indeg[it]++;
        //     }
        // }

        queue<int> q;
        for(int i=0 ; i<n ; i++){
            if(indeg[i] == 0) q.push(i);
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

        sort(ans.begin() , ans.end());
        return ans;
    }
};