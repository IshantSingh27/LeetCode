class Solution {
public:
    void solve(int node , vector<vector<int>>& adj , vector<int>& vis){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                solve(it , adj , vis);
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
        vector<int> vis(n);
        int cnt = 0;

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                solve(i , adj , vis);
                cnt++;
            }
        }

        return cnt;
    }
};