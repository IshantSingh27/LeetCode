class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) {
        if (arr.empty() || arr[0].empty()) return false;  // Handle empty matrix case
        
        int n = arr.size(), m = arr[0].size();
        int s = 0, e = n * m - 1;  // Fix upper bound

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int row = mid / m, col = mid % m;  // Convert 1D index to 2D indices

            if (arr[row][col] == t) return true;
            else if (arr[row][col] < t) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }
};
