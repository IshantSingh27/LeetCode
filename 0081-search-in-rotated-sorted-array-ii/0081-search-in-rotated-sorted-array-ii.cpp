class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int s = 0, e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // If found target, return true
            if (nums[mid] == t) return true;

            // Handle duplicates: shrink search space
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
                continue;
            }

            // If left half is sorted
            if (nums[s] <= nums[mid]) {
                if (t >= nums[s] && t < nums[mid]) {
                    e = mid - 1;  // Search in the left half
                } else {
                    s = mid + 1;  // Search in the right half
                }
            } 
            // If right half is sorted
            else {
                if (t > nums[mid] && t <= nums[e]) {
                    s = mid + 1;  // Search in the right half
                } else {
                    e = mid - 1;  // Search in the left half
                }
            }
        }

        return false;  // Target not found
    }
};
