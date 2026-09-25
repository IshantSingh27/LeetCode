class Solution {
public:
    bool chk(int i ,int j , vector<string>& temp){
        int row = i , col = j;
        while(row >= 0){
            if(temp[row][col] == 'Q') return false;
            row--;
        }
        row = i;
        while(row >= 0 && col >= 0){
            if(temp[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = i;
        col = j;
        while(row >= 0 && col < temp.size()){
            if(temp[row][col] == 'Q') return false;
            row--;
            col++;
        }

        return true;
    }
    void sol(int n , vector<string>& temp , vector<vector<string>>& ans){
        if(n == temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0 ; i<temp.size() ; i++){
            if(chk(n , i , temp)){
                temp[n][i] = 'Q';
                sol(n + 1 , temp , ans);
                temp[n][i] = '.';
            }
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n , '.');
        vector<string> temp(n , s);

        sol(0 , temp , ans);

        return ans;
    }
};