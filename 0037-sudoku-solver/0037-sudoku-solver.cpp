class Solution {
public:
    bool chk(int row , int col , char c , vector<vector<char>>& arr){
        for(int i=0 ; i<9 ; i++){
            if(i != col && arr[row][i] == c) return false;

            if(i != row && arr[i][col] == c) return false;

            if(arr[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == c) return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& arr){
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(arr[i][j] != '.') continue;

                for(char k='1' ; k<='9' ; k++){
                    if(chk(i , j , k , arr)){
                        arr[i][j] = k;
                        if(solve(arr)) return true;
                        arr[i][j] = '.';
                    }
                }

                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& arr) {
        solve(arr);
    }
};