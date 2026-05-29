class Solution {
public:
    void sol(int ind , int tar , vector<int>& temp , vector<vector<int>>& ans , vector<int>& arr){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<arr.size() ; i++){
            if(i > ind && arr[i] == arr[i - 1]) continue;

            if(arr[i] > tar) break;
            temp.push_back(arr[i]);
            sol(i + 1 , tar - arr[i] , temp , ans , arr);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        sol(0 , tar , temp , ans , arr);
        return ans;
    }
};