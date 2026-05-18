class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int cur = arr[0] , n = arr.size() , cnt = 1;
        for(int i=1 ; i<n ; i++){
            if(arr[i] != cur){
                cnt--;
            }
            else cnt++;

            if(cnt < 0){
                cur = arr[i];
                cnt = 1;
            }
        }

        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(arr[i] == cur) ans++;
        }
        if(ans > n/2) return cur;
        else return -1;
    }
};