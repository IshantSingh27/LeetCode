class Solution {
public:
    void solve(int ind , vector<int>& temp , vector<int> arr , vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int i=ind ; i<arr.size() ; i++){
            if(i > ind && arr[i] == arr[i - 1]) continue;

            temp.push_back(arr[i]);
            solve(i + 1 , temp , arr , ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(arr.begin() , arr.end());

        solve(0 , temp , arr , ans);

        return ans;
    }
};