class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        long long n = arr.size();
        long long s = 0 , e = n - 1;
        while(s <= e){
            long long mid = s + (e - s) / 2;

            long long left = LLONG_MIN , right = LLONG_MIN;
            if(mid > 0) left = arr[mid - 1];
            if(mid < n - 1) right = arr[mid + 1];

            if(arr[mid] > left && arr[mid] > right){
                return mid;
            }
            else if(arr[mid] > left && arr[mid] < right){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return s;
    }
};