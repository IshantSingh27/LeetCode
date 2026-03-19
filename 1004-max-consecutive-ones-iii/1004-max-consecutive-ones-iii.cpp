class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size() , i = 0 , j = 0 , ans = 0;

        while(i < n){
            if(arr[i] == 1){
                ans = max(ans , i - j + 1);
                i++;
            }
            else{
                if(k > 0){
                    k--;
                    ans = max(ans , i - j + 1);
                    i++;
                    cout<<"here at index : "<<i<<endl;
                }
                else{
                    while(arr[j] != 0){
                        j++;
                    }
                    j++;
                    k++;
                }
            }
        }

        return ans;
    }
};