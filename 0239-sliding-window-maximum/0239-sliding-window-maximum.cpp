class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size() , l = 0;
        vector<int> ans;

        for(int i=0 ; i<n ; i++){
            if(i < k - 1){
                if(arr[i] >= arr[l]){
                    l = i;
                }
            }
            else{
                if(i - l + 1 > k){
                    l++;
                    int temp = l;
                    while(temp <= i){
                        if(arr[temp] >= arr[l]){
                            l = temp;
                        }
                        temp++;
                    }
                    ans.push_back(arr[l]);
                }
                else{
                    if(arr[i] >= arr[l]) l = i;
                    ans.push_back(arr[l]);
                }
            }
        }
        return ans;
    }
};