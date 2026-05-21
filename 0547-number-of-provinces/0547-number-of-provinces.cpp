class Solution {
public:
    void bfs(int i , vector<vector<int>>& adj , vector<int>& vis){
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(arr[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n , 0);
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                bfs(i , adj , vis);
                ans++;
            }
        }

        return ans;
    }
};