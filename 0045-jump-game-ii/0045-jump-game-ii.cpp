class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size() , l = 0 , r = 0 , jumps = 0;

        while(r < n - 1){
            int maxi = 0;

            for(int i=0 ; i<=r ; i++){
                maxi = max(maxi , i + arr[i]);
            }

            l = r + 1;
            r = maxi;
            jumps++;
        }

        return jumps;
    }
};