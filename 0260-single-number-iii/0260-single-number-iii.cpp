class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        long long n = arr.size() , nums = 0;
        for(long long i=0 ; i<n ; i++){
            nums = (nums ^ arr[i]);
        }

        long long rightmost = ((nums & (nums - 1)) ^ nums);

        long long b1 = 0 , b2 = 0;
        for(int i=0 ; i<n ; i++){
            if((arr[i] & rightmost) != 0){
                b1 = b1 ^ arr[i];
            }
            else b2 = b2 ^ arr[i];
        }

        return {(int)b1 , (int)b2};
    }
};