class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return true;
        int maxi = arr[0] + 0 , i = 0;
        while(i < n && i <= maxi){
            maxi = max(maxi , arr[i] + i);
            if(maxi >= n - 1) return true;
            i++;
        }
        return false;
    }
};