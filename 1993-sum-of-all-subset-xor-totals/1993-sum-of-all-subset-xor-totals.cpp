// class Solution {
// public:
//     int subsetXORSum(vector<int>& arr) {
//         int n = arr.size() , sum = 0;
//         int subsets = (1 << n);

//         for(int i=0 ; i<subsets ; i++){
//             int cur = 0;
//             for(int j=0 ; j<n ; j++){
//                 if((i & (1 << j)) != 0){
//                     cur = cur ^ arr[j];
//                 }
//             }
//             sum = sum + cur;
//         }

//         return sum;
//     }
// };
class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size() , sum = 0;
        
        for(int i=0 ; i<n ; i++){
            sum = sum | arr[i];
        }

        return sum * (1 << (n - 1));
    }
};