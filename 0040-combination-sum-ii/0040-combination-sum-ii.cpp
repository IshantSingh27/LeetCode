class Solution {
public:
    void solve(int ind , int tar , vector<int>& temp , vector<int>& arr, vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(temp);
        }

        for(int i=ind ; i<arr.size() ; i++){
            if(i > ind && arr[i] == arr[i - 1]) continue;

            if(arr[i] <= tar){
                temp.push_back(arr[i]);
                solve(i + 1 , tar - arr[i] , temp , arr , ans);
                temp.pop_back();
            }
            else break;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(arr.begin() , arr.end());

        solve(0 , tar , temp , arr , ans);

        return ans;
    }
};