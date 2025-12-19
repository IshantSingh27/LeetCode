class Solution {
public:
bool safe(int row , int col , vector<vector<char>> &arr , char k){
        for(int i=0 ; i<9 ; i++){
            if(arr[row][i] == k) return false;
            
            if(arr[i][col] == k) return false;
            
            if(arr[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == k) return false;
        }
        
        return true;
    }
  
    bool solve(vector<vector<char>> &arr){
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(arr[i][j] == '.'){
                    
                    for(char k='1' ; k<='9' ; k++){
                        if(safe(i , j , arr , k)){
                            arr[i][j] = k;
                            
                            if(solve(arr)) return true;
                            else{
                                arr[i][j] = '.';
                            }
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }

    void solveSudoku(vector<vector<char>>& arr) {
        solve(arr);
    }
};