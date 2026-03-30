class Solution {
public:
    bool chk(int row , int col , int n , vector<string>& arr){
        int i = row , j = col;
        while(j >= 0){
            if(arr[i][j] == 'Q') return false;
            j--;
        }
        j = col;
        while(i >= 0 && j >= 0){
            if(arr[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        while(i < n && j >= 0){
            if(arr[i][j] == 'Q') return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(int col , int n , vector<string>& arr , vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(arr);
            return;
        }

        for(int i=0 ; i<n ; i++){
            if(chk(i , col , n , arr)){
                arr[i][col] = 'Q';
                solve(col + 1 , n , arr , ans);
                arr[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> arr(n , string(n , '.'));

        solve(0 , n , arr , ans);

        return ans;
    }
};