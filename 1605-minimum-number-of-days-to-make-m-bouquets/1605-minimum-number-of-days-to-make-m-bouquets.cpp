class Solution {
public:
    bool check(vector<int>& arr, int m, int k, int mid){
        long long cnt = 0;
        for(long long i=0 ; i<arr.size() ; i++){
            if(arr[i] <= mid){
                cnt++;
            }
            else{
                cnt = 0;
            }

            if(cnt == k){
                m--;
                cnt = 0;
            }
            if(m == 0){
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& arr, int m, int k) {
        long long n = arr.size();
        if((long long)m * k > n) return -1;
        if((long long)m * k == n) return *max_element(arr.begin(), arr.end());

        long long s = 1 , e = *max_element(arr.begin(), arr.end()) , ans = -1;
        while(s <= e){
            long long mid = s + (e - s) / 2;

            if(check(arr , m , k , mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};