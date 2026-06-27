class Solution {
public:
    bool check(vector<int>& arr) {
        int cnt = 0 , n = arr.size();
        for(int i=1 ; i<n ; i++){
            if(arr[i] < arr[i - 1]) cnt++;
        }
        if(arr[0] < arr[n - 1]) cnt++;

        if(cnt > 1) return false;
        return true;
    }
};