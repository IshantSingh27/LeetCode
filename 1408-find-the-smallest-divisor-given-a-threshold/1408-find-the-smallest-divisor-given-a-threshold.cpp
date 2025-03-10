class Solution {
public:
    bool check(vector<int>& arr, int th, int mid){
        int sum = 0;
        for(int i=0 ; i<arr.size() ; i++){
            sum += (arr[i] + mid - 1) / mid;
        }
        return sum <= th;
    }

    int smallestDivisor(vector<int>& arr, int th) {
        int n = arr.size();
        if(th == n) return *max_element(arr.begin(), arr.end());

        int s = 1 , e = *max_element(arr.begin(), arr.end());
        int ans = *max_element(arr.begin(), arr.end());

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(check(arr , th , mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};