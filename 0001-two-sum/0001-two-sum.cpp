class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int , int>> arr(n);
        for(int i=0 ; i<n ; i++){
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        sort(arr.begin() , arr.end());
        int l = 0 , r = n - 1;

        while(l < r){
            if(arr[r].first + arr[l].first == k){
                return {arr[r].second , arr[l].second};
            }
            else if(arr[r].first + arr[l].first > k){
                r--;
            }
            else{
                l++;
            }
        }

        return {-1};
    }
};