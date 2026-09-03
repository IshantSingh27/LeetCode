class Solution {
public:
    int sol(vector<int>& arr){
        int n = arr.size();
        if(n == 1) return 0;

        vector<int> pre(n) , suf(n);

        pre[0] = arr[0];
        for(int i=1 ; i<n ; i++){
            pre[i] = gcd(pre[i - 1] , arr[i]);
        }

        suf[n - 1] = arr[n - 1];
        for(int i=n - 2 ; i>=0 ; i--){
            suf[i] = gcd(suf[i + 1] , arr[i]);
        }

        int ans = 0;
        for(int i=0 ; i<n-1 ; i++){
            if(pre[i] == suf[i + 1]) ans++;
        }

        return ans;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size() , ans = 0;

        for(int i=-1 ; i<n ; i++){
            vector<int> arr;

            for(int j=0 ; j<n ; j++){
                if(j != i) arr.push_back(nums[j]);
            }

            int cnt = sol(arr);
            ans = max(ans , cnt);
        }

        return ans;
    }
};