class Solution {
public:
    void sol(int ind , int n , vector<int>& temp , vector<vector<int>>& ans , int k){
        if(k == 0){
            if(n == 0) ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<=9 ; i++){
            if(i <= n){
                temp.push_back(i);
                sol(i + 1 , n - i , temp , ans , k - 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        sol(1 , n , temp , ans , k);
        return ans;
    }
};