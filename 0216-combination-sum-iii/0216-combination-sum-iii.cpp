class Solution {
public:
    void sol(int ind , int sum , int n , vector<int>& temp , vector<vector<int>>& ans , int& k){
        if(k == 0){
            if(sum == n) ans.push_back(temp);
            return;
        }

        for(int i=ind ; i<=9 ; i++){
            temp.push_back(i);
            k--;
            sol(i + 1 , sum + i , n , temp , ans , k);
            k++;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        sol(1 , sum , n , temp , ans , k);
        return ans;
    }
};