class Solution {
public:
    int solve(int num , int x){
        int cnt = 0;
        
        while(num != 0){
            int digit = num % 10;
            if(digit == x) cnt++;

            num = num / 10;
        }

        return cnt;
    }
    
    int countDigitOccurrences(vector<int>& arr, int x) {
        int n = arr.size() , cnt = 0;
        
        for(int i=0 ; i<n ; i++){
            cnt += solve(arr[i] , x);
        }

        return cnt;
    }
};