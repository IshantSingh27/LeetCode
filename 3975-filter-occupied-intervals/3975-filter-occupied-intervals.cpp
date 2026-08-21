class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};

        // Step 1: Sort intervals based on their start times
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step 2: Merge overlapping and touching intervals
        vector<vector<int>> merged;
        merged.push_back(occupiedIntervals[0]);
        
        for (int i = 1; i < occupiedIntervals.size(); i++) {
            // Check if they overlap OR touch (e.g., [1,1] and [2,2])
            // They touch if the previous end + 1 is >= current start
            if (merged.back()[1] + 1 >= occupiedIntervals[i][0]) {
                merged.back()[1] = max(merged.back()[1], occupiedIntervals[i][1]);
            } else {
                merged.push_back(occupiedIntervals[i]);
            }
        }

        // Step 3: Remove the free interval from the merged results
        vector<vector<int>> ans;
        for (auto& interval : merged) {
            int start = interval[0];
            int end = interval[1];

            // Case A: The interval is completely outside the free range
            if (end < freeStart || start > freeEnd) {
                ans.push_back({start, end});
            } 
            // Case B: The interval overlaps with the free range (needs cutting)
            else {
                // If there is a valid piece before the free interval, keep it
                if (start < freeStart) {
                    ans.push_back({start, freeStart - 1});
                }
                // If there is a valid piece after the free interval, keep it
                if (end > freeEnd) {
                    ans.push_back({freeEnd + 1, end});
                }
            }
        }

        return ans;
    }
};