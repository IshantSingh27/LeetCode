// class Solution {
// public:
//     int singleNumber(vector<int>& arr) {
//         int ans = 0  , n = arr.size();

//         for(int i=0 ; i<=31 ; i++){
//             int cnt = 0;
//             for(int j=0 ; j<n ; j++){
//                 if( (arr[j] & (1 << i)) != 0 ){
//                     cnt++;
//                 }
//             }

//             if(cnt % 3 != 0){
//                 ans = (ans | (1 << i));
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        sort(arr.begin() , arr.end());

        for(int i=1 ; i<n ; i += 3){
            if(arr[i] != arr[i - 1]) return arr[i - 1];
        }

        return arr[n - 1];
    }
};