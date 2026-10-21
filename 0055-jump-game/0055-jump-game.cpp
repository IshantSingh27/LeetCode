class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() , far = 0 , end = 0;

        for(int i=0 ; i<n-1 ; i++){
            far = max(far , i + nums[i]);

            if(i == end){
                if(end == far) return false;
                end = far;
            }
        }

        if(end >= n - 1) return true;
        else return false;
    }
};