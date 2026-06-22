class Solution {
public:
    bool chk(int row , int col , vector<string>& temp){
        int i = row , j = col;
        while(i >= 0){
            if(temp[i][j] == 'Q') return false;
            i--;
        }

        i = row;
        while(i >=0  && j >= 0){
            if(temp[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = row;
        j = col;
        while(i >= 0 && j >= 0){
            if(temp[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }
    void sol(int row , int n , vector<string>& temp , vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(temp);
            return;
        }

        for(int i=0 ; i<n ; i++){
            if(chk(row , i , temp)){
                temp[row][i] = 'Q';
                sol(row + 1 , n , temp , ans);
                temp[row][i] = '.';
            }
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;

        for(int i=0 ; i<n ; i++){
            string s;
            for(int i=0 ; i<n ; i++){
                s.push_back('.');
            }
            temp.push_back(s);
        }

        sol(0 , n , temp , ans);
        return ans;
    }
};