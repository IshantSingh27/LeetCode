class Solution {
public:
    int maximumWidth(vector<int>& planks) {
         unordered_map<long long, int> freq;

        for (int x : planks) {
            freq[x]++;
        }

        vector<long long> values;

        for (auto &[x, cnt] : freq) {
            values.push_back(x);
        }

        int k = values.size();

        // pairCount[H] = maximum number of planks
        // that can be created by combining pairs with sum H
        unordered_map<long long, int> pairCount;

        // Consider every pair of DISTINCT height values
        for (int i = 0; i < k; i++) {

            // x + x
            long long x = values[i];

            pairCount[2 * x] += freq[x] / 2;

            // x + y
            for (int j = i + 1; j < k; j++) {

                long long y = values[j];

                long long H = x + y;

                int pairs = min(freq[x], freq[y]);

                pairCount[H] += pairs;
            }
        }

        int ans = 0;

        // Existing single planks
        for (auto &[H, cnt] : freq) {
            ans = max(ans, cnt + pairCount[H]);
        }

        // Heights that exist only through pairing
        for (auto &[H, pairs] : pairCount) {
            ans = max(ans, pairs);
        }

        return ans;
    }
};