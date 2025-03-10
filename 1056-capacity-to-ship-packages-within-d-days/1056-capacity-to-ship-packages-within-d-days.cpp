class Solution {
public:
    bool check(vector<int>& arr, int d, int mid) {
        int sum = 0, day = 1;  // Day should start from 1
        for (int i = 0; i < arr.size(); i++) {
            if (sum + arr[i] > mid) {
                day++;
                sum = 0; // Start a new day
            }
            sum += arr[i]; 
        }
        return day <= d;
    }

    int shipWithinDays(vector<int>& arr, int d) {
        int sum = 0, maxVal = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
        }

        int s = maxVal, e = sum, ans = sum;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (check(arr, d, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
