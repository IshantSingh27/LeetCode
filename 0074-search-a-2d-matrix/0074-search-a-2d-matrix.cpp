class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) {
        if (arr.empty() || arr[0].empty()) return false;  // Handle empty matrix case
        
        int n = arr.size(), m = arr[0].size();
        int s = 0, e = n * m - 1;  // Fix upper bound

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid / m][mid % m] == t) return true;
            else if (arr[mid / m][mid % m] < t) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }
};
