class Solution {
public:
    bool sol(long long mid , long long h , vector<int>& arr){
        long long n = arr.size();
        for(long long i=0 ; i<n ; i++){
            long long cur = 0;
            if(arr[i] % mid == 0) cur = arr[i] / mid;
            else cur = (arr[i] / mid) + 1;

            h -= cur;
            if(h < 0) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        long long ans = 0 , s = 1 , e = *max_element(arr.begin() , arr.end());
        while(s <= e){
            long long mid = s + (e - s) / 2;
            if(sol(mid , h , arr)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};