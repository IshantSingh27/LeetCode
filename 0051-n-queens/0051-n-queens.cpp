class Solution {
public:
    bool safe(int row , int col , vector<string>& bod , int n){
        int crow = row , ccol = col;

        while(row >= 0 && col >= 0){
            if(bod[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = crow;
        col = ccol;
        while(col >= 0){
            if(bod[row][col] == 'Q') return false;
            col--;
        }

        row = crow;
        col = ccol;
        while(col >= 0 && row < n){
            if(bod[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void sol(int col, vector<string>& bod, vector<vector<string>>& ans , int n){
        if(col == n){
            ans.push_back(bod);
            return;
        }

        for(int row=0 ; row<n ; row++){
            if(safe(row , col , bod , n)){
                bod[row][col] = 'Q';
                sol(col + 1 , bod , ans , n);
                bod[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> bod(n , string(n , '.'));

        sol(0 , bod , ans , n);

        return ans;
    }
};