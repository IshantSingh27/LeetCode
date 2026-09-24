class Solution {
public:
    void sol(int i , int tar , vector<int>& arr , vector<int>& temp , vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        if(tar < 0){
            return;
        }

        for(int j=i ; j<arr.size() ; j++){
            if(j != i && arr[j] == arr[j - 1]) continue;

            temp.push_back(arr[j]);
            sol(j + 1 , tar - arr[j] , arr , temp , ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        sol(0 , tar , arr , temp , ans);

        return ans;
    }
};