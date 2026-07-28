class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        int n = arr.size() , m = arr[0].size() , s = 0 , e = (n * m) - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(arr[mid / m][mid % m] == tar) return true;
            if(arr[mid / m][mid % m] < tar) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }
};