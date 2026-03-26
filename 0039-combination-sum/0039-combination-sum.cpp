class Solution {
public:
    void solve(int ind , int tar , vector<int>& temp , vector<int>& arr , vector<vector<int>>& ans){
        if(ind == arr.size()){
            if(tar == 0) ans.push_back(temp);
            return;
        }

        solve(ind + 1 , tar , temp , arr , ans);
        if(tar >= arr[ind]){
            temp.push_back(arr[ind]);
            solve(ind , tar - arr[ind] , temp , arr , ans);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0 , tar , temp , arr , ans);

        return ans;
    }
};