class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0 , e = n - 1;
        if( k <= arr[0] - (1) ) return k;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(arr[mid] - (mid + 1) < k){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        // return arr[e] + ( k - ( arr[e] - (e + 1) ) );
        return e + k + 1;
    }
};