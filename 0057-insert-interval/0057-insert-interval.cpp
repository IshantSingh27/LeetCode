class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& nw) {
        vector<vector<int>> ans;
        int i = 0 , n = arr.size();
        while(i < n && arr[i][1] < nw[0]){
            ans.push_back(arr[i]);
            i++;
        }

        while(i < n && arr[i][0] <= nw[1]){
            nw[0] = min(nw[0] , arr[i][0]);
            nw[1] = max(nw[1] , arr[i][1]);
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