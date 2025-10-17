class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size() , lsum = 0 , rsum = 0 , maxi = 0 , rind = n - 1;

        for(int i=0 ; i<k ; i++){
            lsum += arr[i];
            maxi = max(maxi , lsum);
        }

        for(int i=k - 1 ; i>=0 ; i--){
            lsum -= arr[i];

            rsum += arr[rind];
            rind--;

            maxi = max(maxi , lsum + rsum);
        }

        return maxi;
    }
};