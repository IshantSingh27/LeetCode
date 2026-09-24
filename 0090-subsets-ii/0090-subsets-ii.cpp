class Solution {
public:
    void sol(int i , vector<int>& arr , vector<int>& temp , vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int j=i ; j<arr.size() ; j++){
            if(j != i && arr[j] == arr[j - 1]) continue;

            temp.push_back(arr[j]);
            sol(j + 1 , arr , temp , ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        vector<int> temp;

        sol(0 , arr , temp , ans);

        return ans;
    }
};