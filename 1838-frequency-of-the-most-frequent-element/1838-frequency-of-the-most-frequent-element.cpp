class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin() , arr.end());
        long long n = arr.size() , sum = 0 , left = 0 , ans = 1;

        for(int right=0 ; right<n ; right++){
            sum += arr[right];

            while(left <= right && (long long)(arr[right] * (right - left + 1)) - sum > k){
                sum -= arr[left];
                left++;
            }

            if(right - left + 1 > ans){
                ans = right - left + 1;
            }
        }

        return ans;
    }
};