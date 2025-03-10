class Solution {
public:
    bool check(vector<int>& arr, int h, int mid) {
        long long totalHours = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalHours += (arr[i] + mid - 1) / mid; // Correct integer ceiling
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int s = 1, e = *max_element(arr.begin(), arr.end()), ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(arr, h, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
