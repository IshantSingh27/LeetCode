class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();

        int s = 0 , e = n-1 , ans = -1;
        while(s <= e){
            int mid = s + (e-s) / 2;

            if(nums[mid] == t){
                ans = mid;
                e = mid - 1;
            }

            else if(nums[mid] < t){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        if(ans == -1) return {-1 , -1};

        int ans2 = -1;
        s = 0 , e = n-1;
        while(s <= e){
            int mid = s + (e-s) / 2;

            if(nums[mid] == t){
                ans2 = mid;
                s = mid + 1;
            }

            else if(nums[mid] < t){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return {ans , ans2};
    }
};