class Solution {
public:
    void sol(int ind , int k , int tar , vector<int>& temp , vector<vector<int>>& ans){
        if(k == 0){
            if(tar == 0) ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<10 ; i++){
            if(i > tar) break;
            
            temp.push_back(i);
            sol(i + 1 , k - 1 , tar - i , temp , ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        sol(1 , k , tar , temp , ans);
        return ans;
    }
};