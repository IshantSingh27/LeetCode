class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {

        // k = 1 is always possible.
        // Make one simple path:
        // first row -> last column
        if (k == 1) {
            vector<string> grid(m, string(n, '#'));

            // First row
            for (int j = 0; j < n; j++)
                grid[0][j] = '.';

            // Last column
            for (int i = 0; i < m; i++)
                grid[i][n - 1] = '.';

            return grid;
        }

        // If n >= k, construct using first two rows.
        //
        // Example k = 3:
        //
        // ....
        // #...
        // ###
        // ###
        //
        // Then extend the last column downward.
        if (n >= k && m >= 2) {

            vector<string> grid(m, string(n, '#'));

            // First row is completely free
            for (int j = 0; j < n; j++)
                grid[0][j] = '.';

            // Last k cells of second row are free
            for (int j = n - k; j < n; j++)
                grid[1][j] = '.';

            // From (1,n-1) to bottom-right, only one path
            for (int i = 2; i < m; i++)
                grid[i][n - 1] = '.';

            return grid;
        }

        // If m >= k, do the same construction vertically.
        if (m >= k && n >= 2) {

            vector<string> grid(m, string(n, '#'));

            // First column is completely free
            for (int i = 0; i < m; i++)
                grid[i][0] = '.';

            // Last k cells of second column are free
            for (int i = m - k; i < m; i++)
                grid[i][1] = '.';

            // From (m-1,1) to bottom-right, only one path
            for (int j = 2; j < n; j++)
                grid[m - 1][j] = '.';

            return grid;
        }

        // The only remaining possible case for k = 4:
        // m = n = 3
        //
        // ..#
        // ...
        // #..
        //
        // This gives exactly 4 paths.
        if (m == 3 && n == 3 && k == 4) {
            return {
                "..#",
                "...",
                "#.."
            };
        }

        // No construction possible.
        return {};
    }
};