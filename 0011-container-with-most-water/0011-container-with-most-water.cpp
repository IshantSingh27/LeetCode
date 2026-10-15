class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i = 0 , j = arr.size() - 1 , ans = 0;

        while(i < j){
            int width = j - i;
            int height = min(arr[i] , arr[j]);

            ans = max(ans , width * height);

            if(arr[i] < arr[j]){
                i++;
            }
            else j--;
        }

        return ans;
    }
};