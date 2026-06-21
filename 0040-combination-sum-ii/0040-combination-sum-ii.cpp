class Solution {
public:
    void sol(int ind , int k , vector<int>& arr , vector<int>& temp , vector<vector<int>>& ans){
        if(k == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<arr.size() ; i++){
            if(i > ind && arr[i] == arr[i - 1]) continue;
            if(arr[i] > k) break;

                temp.push_back(arr[i]);
                sol(i + 1 , k - arr[i] , arr , temp , ans);
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