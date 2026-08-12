class Solution {
public:
    bool sol(int k, const vector<vector<int>>& prefix) {
        int n = prefix.size() - 1, m = prefix[0].size() - 1;
        
        int min_r = INT_MAX, max_r = INT_MIN;
        int min_c = INT_MAX, max_c = INT_MIN;

        for (int i = 0; i + k <= n; i++) {
            for (int j = 0; j + k <= m; j++) {
                int sum = prefix[i + k][j + k] - prefix[i + k][j] -
                          prefix[i][j + k] + prefix[i][j];

                if (sum == k * k) {
                    min_r = min(min_r, i);
                    max_r = max(max_r, i);
                    min_c = min(min_c, j);
                    max_c = max(max_c, j);
                }
            }
        }
        
        // If no squares of size k were found at all
        if (min_r == INT_MAX) return false;

        // True if the bounding box of all valid squares allows for 2 non-overlapping squares
        return (max_r - min_r >= k) || (max_c - min_c >= k);
    }

    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] +
                                       prefix[i + 1][j] - prefix[i][j];
            }
        }

        int s = 1, e = min(m, n), ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (sol(mid, prefix)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return ans * ans;
    }
};