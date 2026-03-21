class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size() , sum = 0 , l = k - 1 , r = n - 1;
        if(n < k){
            for(int i=0 ; i<n ; i++){
                sum += arr[i];
            }
            return sum;
        }

        for(int i=0 ; i<k ; i++){
            sum += arr[i];
        }

        int ans = sum;
        for(int i=0 ; i<k ; i++){
            sum += arr[r - i];
            sum -= arr[l - i];

            ans = max(ans , sum);
        }

        return ans;
    }
};