class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = parent.size();

        // depth[i] = depth of node i
        // root has depth 1
        vector<long long> depth(n, 0);

        long long h = 1;

        for (int i = 0; i < n; i++) {

            if (depth[i] != 0) {
                h = max(h, depth[i]);
                continue;
            }

            // Store nodes whose depth we need to calculate
            vector<int> path;

            int node = i;

            // Move upward until we reach a node
            // whose depth is already known or root.
            while (depth[node] == 0 && parent[node] != -1) {
                path.push_back(node);
                node = parent[node];
            }

            // If root is reached
            if (parent[node] == -1 && depth[node] == 0) {
                depth[node] = 1;
            }

            // Work backwards and assign depths
            for (int j = path.size() - 1; j >= 0; j--) {
                depth[path[j]] = depth[parent[path[j]]] + 1;
            }

            h = max(h, depth[i]);
        }

        // Your original formula
        h++;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (h - depth[i]);
        }

        return ans;
    }
};