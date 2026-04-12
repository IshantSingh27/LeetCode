class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> adj(n , 0);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(arr[i][j] == 1){
                    adj[i]++;
                }
            }
        }

        return adj;
    }
};