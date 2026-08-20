class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        
        // 1. Precompute primes up to sqrt(10^9) to quickly factorize elements
        vector<int> primes;
        vector<bool> is_prime(31625, true);
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i <= 31622; ++i){
            if(is_prime[i]){
                primes.push_back(i);
                for(int j = i * i; j <= 31622; j += i){
                    is_prime[j] = false;
                }
            }
        }
        
        // 2. Precompute prefix sums to quickly calculate penalties between spikes
        vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        // 3. Map each unique prime factor to the indices where it divides nums[i]
        unordered_map<int, vector<int>> prime_indices;
        for(int i = 0; i < n; ++i) {
            int temp = nums[i];
            for(int p : primes) {
                if (p * p > temp) break;
                if (temp % p == 0) {
                    prime_indices[p].push_back(i);
                    while (temp % p == 0) temp /= p;
                }
            }
            if (temp > 1) { // Remaining prime factor
                prime_indices[temp].push_back(i);
            }
        }
        
        // Default Case: In the rare case no elements have prime factors (e.g., all 1s),
        // any k yields a negative sum. The best we can do is the smallest penalty.
        long long max_diff = -1e18;
        int best_k = 2; 
        for (int x : nums) {
            if (-(long long)x > max_diff) {
                max_diff = -(long long)x;
            }
        }
        
        // 4. Run an optimized Kadane's Algorithm for each collected prime
        for (auto const& [p, indices] : prime_indices) {
            long long curr_max = -1e18;
            long long curr_sum = 0;
            
            for (int j = 0; j < indices.size(); ++j) {
                int idx = indices[j];
                
                // If there's a gap between the current and previous divisible element, apply the negative penalty
                if (j > 0) {
                    long long neg_penalty = - (pref[idx] - pref[indices[j - 1] + 1]);
                    curr_sum += neg_penalty;
                    if (curr_sum < 0) curr_sum = 0;
                }
                
                // Add the positive spike
                curr_sum += nums[idx];
                
                if (curr_sum > curr_max) curr_max = curr_sum;
                if (curr_sum < 0) curr_sum = 0;
            }
            
            // 5. Update our global trackers
            if (curr_max > max_diff) {
                max_diff = curr_max;
                best_k = p;
            } else if (curr_max == max_diff && p < best_k) {
                // If there is a tie, Alice prefers the smaller k
                best_k = p;
            }
        }
        
        // 6. Calculate the final answer taking modulo constraints into account
        long long ans = max_diff % MOD;
        ans = (ans * best_k) % MOD;
        
        // C++ modulo on negative numbers can return negative, ensure it wraps around cleanly
        if (ans < 0) ans += MOD;
        
        return ans;
    }
};