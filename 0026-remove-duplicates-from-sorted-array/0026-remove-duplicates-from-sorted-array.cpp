class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int ans = 1 , k = 1;
        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i] != arr[i - 1]){
                arr[k] = arr[i];
                k++;
                ans++;
            }
        }
        return ans;
    }
};