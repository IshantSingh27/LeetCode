class Solution {
public:
    void sol(int ind , vector<int>& arr , vector<int>& temp , vector<vector<int>>& ans){
        if(ind == arr.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<arr.size() ; i++){
            swap(arr[i] , arr[ind]);
            temp.push_back(arr[ind]);
            sol(ind + 1 , arr , temp , ans);
            temp.pop_back();
            swap(arr[i] , arr[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& arr) {
        vector<int> temp;
        vector<vector<int>> ans;

        sol(0 , arr , temp , ans);

        return ans;
    }
};