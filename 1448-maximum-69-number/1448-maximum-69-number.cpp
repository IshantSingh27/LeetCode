class Solution {
public:
    int maximum69Number (int num) {
        vector<int> ans;
        int temp = num;

        // Extract digits in correct order (reversed)
        while (temp > 0) {
            ans.push_back(temp % 10);
            temp /= 10;
        }
        reverse(ans.begin(), ans.end()); // Fix digit order

        // Change first occurrence of '6' to '9'
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 6) { // Corrected condition
                ans[i] = 9;
                break; // Stop after first change
            }
        }

        // Convert vector back to integer
        int res = 0;
        for (int digit : ans) {
            res = res * 10 + digit;
        }

        return res;
    }
};
