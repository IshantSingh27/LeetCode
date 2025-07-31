class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans = 0  , n = arr.size();

        for(int i=0 ; i<=31 ; i++){
            int cnt = 0;
            for(int j=0 ; j<n ; j++){
                if( (arr[j] & (1 << i)) != 0 ){
                    cnt++;
                }
            }

            if(cnt % 3 != 0){
                ans = (ans | (1 << i));
            }
        }

        return ans;
    }
};