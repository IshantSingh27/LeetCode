class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int ans = 1 , i = 1;
        while(i < arr.size()){
            if(arr[i] == arr[i - 1]){
                arr.erase(arr.begin() + i - 1);
            }
            else{
                ans++;
                i++;
            }
        }
        return ans;
    }
};