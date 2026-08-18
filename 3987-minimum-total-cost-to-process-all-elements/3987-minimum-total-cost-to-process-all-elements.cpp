class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cnt = 0 , cur = k , mod = 1e9 + 7;

        for(auto x : nums){
            if(x > cur){
                long long need = (x - cur + k - 1LL) / k;

                cnt += need;
                cur += need * k;
            }

            cur -= x;
        }

        cnt = cnt % mod;

        return (int)(((cnt * (cnt + 1)) / 2) % mod);
    }
};