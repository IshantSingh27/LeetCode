class Solution {
public:
    bool subsetSum(int n , int k , vector<int>& arr){
        vector<bool> prev(k + 1 , false) , cur(k + 1 , false);
        prev[0] = true;
        cur[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int i=1 ; i<n ; i++){
            for(int tar=1 ; tar<=k ; tar++){
                bool notTake = prev[tar];
                bool take = false;
                if(tar >= arr[i]){
                    take = prev[tar - arr[i]];
                }
                cur[tar] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        if(sum % 2 != 0) return false;
        else{
            return subsetSum(nums.size() , sum / 2 , nums);
        }
    }
};