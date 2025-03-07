class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();

        int s = 0 , e = n-1;
        while(s <= e){
            int mid = s + (e-s) / 2;

            if(nums[mid] == t){
                return mid;
            }

            else if(nums[mid] > t){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return -1;
    }
};