class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size() , lsum = 0 , rsum = 0;
        for(int i=0 ; i<k ; i++) lsum += arr[i];
        if(k == n) return lsum;
        int maxi = lsum , r = n - 1;
        // cout<<"maxi : "<<maxi<<endl;
        for(int i = k-1 ; i >= 0 ; i--){
            // cout<<"arr[i] : "<<arr[i]<<" arr[n - i - 1] : "<<arr[n - i - 1];
            lsum -= arr[i];
            rsum += arr[r--];
            // cout<<" total : "<<lsum + rsum<<endl;
            maxi = max(maxi , lsum + rsum);
        }
        return maxi;
    }
};