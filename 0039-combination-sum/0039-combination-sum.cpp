class Solution {
public:
    void sol(int ind, vector<int>& arr, int tar, vector<int>& temp, vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        if(ind == arr.size()){
            if(tar == 0) ans.push_back(temp);
            return;
        }

        sol(ind + 1 , arr , tar , temp , ans);

        if(arr[ind] <= tar){
            temp.push_back(arr[ind]);
            sol(ind , arr , tar - arr[ind] , temp , ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;

        sol(0 , arr , tar , temp , ans);

        return ans;
    }
};