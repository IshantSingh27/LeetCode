class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) {
        int n = arr.size() , m = arr[0].size();
        int row = 0 , col = m  - 1;
        while(row < n && col >= 0){
            if(arr[row][col] == t) return true;
            else if(arr[row][col] < t){
                row ++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};