class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> arr;

        // If there are fewer than 4 numbers, return an empty result
        if (n < 4) return {};

        // Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate values for `i`
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate values for `j`
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        arr.push_back({nums[i], nums[j], nums[k], nums[l]});

                        // Skip duplicate values for `k`
                        while (k + 1 < l && nums[k] == nums[k + 1]) k++;
                        // Skip duplicate values for `l`
                        while (l - 1 > k && nums[l] == nums[l - 1]) l--;

                        // Move pointers after handling duplicates
                        k++;
                        l--;
                    } else if (sum < target) {
                        k++; // Increase the sum by moving `k` forward
                    } else {
                        l--; // Decrease the sum by moving `l` backward
                    }
                }
            }
        }

        return arr;
    }
};
