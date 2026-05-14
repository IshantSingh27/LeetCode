class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n , 1);

        for(int i=1 ; i<n ; i++){
            if(arr[i - 1] < arr[i]) left[i] = left[i - 1] + 1;
        }

        int right = 1 , cur = 0 , sum = max(1 , left[n - 1]);
        for(int i=n-2 ; i>=0 ; i--){
            if(arr[i] > arr[i + 1]){
                int cur = right + 1;
                right  = cur;
            }
            else{
                right = 1;
            }

            sum += max(left[i] , right);
        }

        return sum;
    }
};