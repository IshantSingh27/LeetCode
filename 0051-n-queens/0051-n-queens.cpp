class Solution {
public:
    bool check(int row , int col , int n , vector<string>& temp){
        if(row == 0) return true;

        for(int i=0 ; i<row ; i++){
            if(temp[i][col] == 'Q') return false;
        }

        int i = row - 1 , j = col + 1;
        while(i >= 0 && j < n){
            if(temp[i][j] == 'Q') return false;
            i--;
            j++;
        }

        i = row - 1 , j = col - 1;
        while(i >= 0 && j >= 0){
            if(temp[i][j] == 'Q') return false;
            i--;
            j--;
        }

        return true;
    }
    bool sol(int i , int  n , vector<string>& temp , vector<vector<string>>& ans){
        if(i == n){
            ans.push_back(temp);
            return true;
        }

        for(int j=0 ; j<n ; j++){
            if(check(i , j , n , temp)){
                temp[i][j] = 'Q';
                if(!sol(i + 1 , n , temp , ans)) return false;
                temp[i][j] = '.';
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                temp[i] += '.';
            }
        }
        sol(0 , n , temp , ans);
        return ans;
    }
};