class Solution {
public:
    void sol(int ind , int tar , vector<int>& arr , vector<int>& temp , vector<vector<int>>& ans){
        if(ind < 0){
            if(tar == 0) ans.push_back(temp);
            return;
        }

        sol(ind - 1 , tar , arr , temp , ans);

        if(arr[ind] <= tar){
            temp.push_back(arr[ind]);
            sol(ind , tar - arr[ind] , arr , temp , ans);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = arr.size();

        sol(n - 1 , tar , arr , temp , ans);

        return ans;
    }
};