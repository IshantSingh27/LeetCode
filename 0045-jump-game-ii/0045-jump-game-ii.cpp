class Solution {
public:
    int jump(vector<int>& arr) {
        int i = 0 , n = arr.size() , ans = 0;
        if(n == 1) return 0;

        while(i < n){
            int jump = i + arr[i] , j = i , maxi = 0 , pos = i;
            ans++;

            if(jump >= n - 1){
                return ans;
            }

            while(j <= jump){
                if(j + arr[j] >= maxi){
                    maxi = j + arr[j];
                    pos = j;
                }
                j++;
            }
            // cout<<"i : "<<i<<" maxi : "<<maxi<<" pos : "<<pos<<" ans : "<<ans<<endl;
            if(pos == i) return -1;
            i = pos;
        }
        return -1;
    }
};