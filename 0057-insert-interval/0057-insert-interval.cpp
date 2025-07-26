class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& nw) {
        int n = arr.size();
        vector<vector<int>> ans;
        int i=0;
        
        while(i < n && arr[i][1] < nw[0]){
            ans.push_back(arr[i]);
            i++;
        }

        while(i < n && arr[i][0] <= nw[1]){
            nw[0] = min(arr[i][0] , nw[0]);
            nw[1] = max(arr[i][1] , nw[1]);
            i++;
        }
        ans.push_back(nw);

        while(i < n){
            ans.push_back(arr[i]);
            i++;
        }

        return ans;
    }
};