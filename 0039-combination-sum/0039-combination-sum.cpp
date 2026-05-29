class Solution {
public:
    void sol(int i , int tar , vector<int>& temp , vector<vector<int>>& ans , vector<int>& arr){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        for(int ind = i ; ind<arr.size() ; ind++){
            if(arr[ind] > tar) break;
            
            temp.push_back(arr[ind]);
            sol(ind , tar - arr[ind] , temp , ans , arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sol(0 , tar , temp , ans , arr);
        return ans;
    }
};