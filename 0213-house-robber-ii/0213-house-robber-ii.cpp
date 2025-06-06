class Solution {
public:
    long long rob1(vector<long long>& nums) {
        long long n = nums.size();
        long long prev = nums[0] , prev1 = 0;  //space
        for(long long i=1 ; i<n ; i++){
            long long pick = nums[i] + prev1; //space
            long long notpick = prev;
            long long cur = max(pick , notpick);
            prev1 = prev;
            prev = cur;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<long long> t1 , t2;
        for(long long i=0 ; i<nums.size() ; i++){
            if(i != 0) t1.push_back(nums[i]);
            if(i != nums.size() - 1) t2.push_back(nums[i]);
        }
        return max(rob1(t1) , rob1(t2));
    }
};