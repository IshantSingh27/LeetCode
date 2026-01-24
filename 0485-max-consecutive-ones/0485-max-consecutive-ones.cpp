class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0 , i = 0 , n = nums.size();

        while(i < n){
            int j = i , cnt = 0;

            while(j < n && nums[j] == 1){
                j++;
            }

            cnt += j - i;
            ans = max(ans , cnt);
            if(i == j){
                i++;
            }
            else i = j;
        }

        return ans;
    }
};