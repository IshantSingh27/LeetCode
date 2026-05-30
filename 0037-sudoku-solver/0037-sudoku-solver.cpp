class Solution {
public:
    bool check(int row , int col , char k , vector<vector<char>>& arr){
        for(int i=0 ; i<9 ; i++){
            if(i != row && arr[i][col] == k) return false;
            if(i != col && arr[row][i] == k) return false;
            if(arr[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == k) return false;
        }
        return true;
    }
    bool sol(vector<vector<char>>& arr){
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(arr[i][j] != '.') continue;

                for(char k='1' ; k<='9' ; k++){
                    if(check(i , j , k , arr)){
                        arr[i][j] = k;
                        if(sol(arr)) return true;
                        arr[i][j] = '.';
                    }
                }

                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& arr) {
        sol(arr);
    }
};