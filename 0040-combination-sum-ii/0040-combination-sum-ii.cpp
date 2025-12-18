class Solution {
public:
    void sol(int ind, vector<int>& arr, int tar, vector<int>& temp, vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<arr.size() ; i++){
            if(i != ind && arr[i] == arr[i - 1]) continue;
            if(arr[i] > tar) break;

            if(arr[i] <= tar){
                temp.push_back(arr[i]);
                sol(i + 1 , arr , tar- arr[i] , temp , ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(arr.begin() , arr.end());
        sol(0 , arr , tar , temp , ans);

        return ans;
    }
};