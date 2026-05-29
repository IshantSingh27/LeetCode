class Solution {
public:
    void sol(int ind , vector<int>& temp , vector<vector<int>>& ans , vector<int>& arr){
        ans.push_back(temp);

        for(int i=ind ; i<arr.size() ; i++){
            temp.push_back(arr[i]);
            sol(i + 1 , temp , ans , arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> temp;
        vector<vector<int>> ans;
        sol(0 , temp , ans , arr);
        return ans;
    }
};