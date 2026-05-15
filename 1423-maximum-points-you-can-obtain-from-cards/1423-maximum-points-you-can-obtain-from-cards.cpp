class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size() , sum = 0;

        for(int i = n-k ; i<n ; i++){
            sum += arr[i];
        }
        int ans = sum;
        for(int i = n-k ; i<n ; i++){
            sum = sum + arr[i - (n - k)] - arr[i];
            ans = max(ans , sum);
        }

        return ans;
    }
};