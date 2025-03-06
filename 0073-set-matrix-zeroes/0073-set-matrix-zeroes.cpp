// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size() , m = matrix[0].size();
//         vector<int> row(n , 0) , col(m , 0);
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<m ; j++){
//                 if(matrix[i][j] == 0){
//                     row[i] = 1;
//                     col[j] = 1;
//                 }
//             }
//         }
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<m ; j++){
//                 if(row[i] || col[j]){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         return;
//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Step 1: Mark rows and columns using first row and first column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRow = true;
                    if (j == 0) firstCol = true;
                    matrix[i][0] = 0; // Mark the first column
                    matrix[0][j] = 0; // Mark the first row
                }
            }
        }

        // Step 2: Set matrix cells to zero using markers (ignoring first row & column for now)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row if needed
        if (firstRow) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle the first column if needed
        if (firstCol) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
