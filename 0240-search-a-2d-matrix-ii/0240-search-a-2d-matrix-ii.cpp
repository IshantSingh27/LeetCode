class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        int n = arr.size() , m = arr[0].size() , row = 0 , col = m - 1;
        while(row < n && col >= 0){
            if(arr[row][col] == tar) return true;
            if(tar < arr[row][col]) col--;
            else row++;
        }
        return false;
    }
};