class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long cur = k;   // currently available capacity
        long long cnt = 0;   // number of extra operations

        for (long long x : nums) {

            if (x > cur) {
                // Number of extra k-sized operations needed
                long long need = (x - cur + k - 1LL) / k;

                cnt += need;
                cur += need * k;
            }

            // Process this element
            cur -= x;
        }

        cnt %= MOD;

        // 1 + 2 + ... + cnt
        return (int)((cnt * (cnt + 1) / 2) % MOD);
    }
};