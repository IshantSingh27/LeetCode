class Solution {
public:
    int sol(int mid , int h , vector<int>& arr){
        int ind = 0;
        while(ind < arr.size() && h > 0){
            int cur = 0;
            // cout<<"arr[ind] : "<<arr[ind];
            if(arr[ind] % mid == 0) cur += arr[ind] / mid;
            else cur += (arr[ind] / mid) + 1;
            // cout<<" cur : "<<cur<<endl;;
            h -= cur;
            if(h >= 0) ind++;
        }
        return ind == arr.size();
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int s = 1 , e = *max_element(arr.begin() , arr.end()) , ans = INT_MAX;
        while(s <= e){
            int mid = s + (e - s) / 2;
            // cout<<"mid : "<<mid<<endl;
            if(!sol(mid , h , arr)){
                s = mid + 1;
            }
            else{
                ans = min(ans , mid);
                e = mid - 1;
            }
        }
        return ans;
    }
};