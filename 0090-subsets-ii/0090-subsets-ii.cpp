class Solution {
public:
    void sol(int ind , vector<int>& arr , vector<int>& temp , vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int i=ind ; i<arr.size() ; i++){
            if(i > ind && arr[i] == arr[i - 1]) continue;

            temp.push_back(arr[i]);
            sol(i + 1 , arr , temp , ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin() , arr.end());
        sol(0 , arr , temp , ans);
        return ans;
    }
};