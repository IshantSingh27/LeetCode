// class Solution {
// public:
//     int candy(vector<int>& arr) {
//         int i = 1 , sum = 1 , n = arr.size();

//         while(i < n){
//             while(i < n && arr[i] == arr[i - 1]){
//                 sum++;
//                 i++;
//             }
//             int peak = 1;
//             while(i < n && arr[i] > arr[i - 1]){
//                 sum += peak;
//                 peak += 1;
//                 i++;
//             }
//             int down = 1;
//             while(i < n && arr[i] < arr[i - 1]){
//                 sum += down;
//                 down += 1;
//                 i++;
//             }
//             if(down >= peak){
//                 sum += (down - peak) + 1;
//             }
//         }

//         return sum;
//     }
// };
class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n , 1);

        for(int i=1 ; i<n ; i++){
            if(arr[i] > arr[i - 1]) left[i] = left[i - 1] + 1;
        }

        int cur = 1 , right = 1 , sum = max(left[n - 1] , 1);
        for(int i=n-2 ; i>=0 ; i--){
            if(arr[i] > arr[i + 1]){
                cur = right + 1;
                right = cur;
            }
            else{
                right = 1;
                cur = 1;
            }

            sum += max(left[i] , cur);
        }

        return sum;
    }
};