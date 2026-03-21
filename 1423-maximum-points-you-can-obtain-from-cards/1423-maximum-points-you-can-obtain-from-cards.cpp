class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size() , sum = 0 , l = n - k , ans = 0;
        if(n < k){
            for(int i=0 ; i<n ; i++){
                sum += arr[i];
            }
            return sum;
        }

        for(int i = n-k ; i < n+k ; i++){
            if(i < n) sum += arr[i];
            else{
                sum += arr[i % n];
                sum -= arr[l % n];
                l++;
            }
            cout<<"Sum : "<<sum<<endl;

            ans = max(ans , sum);
        }

        return ans;
    }
};