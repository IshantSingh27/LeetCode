class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int s = 0 , e = nums.size() - 1;

        while(s <= e){
            int mid = s + (e - s) / 2;
            cout<<"mid : "<<mid<<" nums : "<<nums[mid]<<endl;

            if(tar == nums[mid]) return true;

            if(nums[s] == nums[mid] && nums[e] == nums[mid]){
                s++;
                e--;
                continue;
            }

            if((nums[e] >= nums[mid])){
                if(tar > nums[mid] && tar <= nums[e]){
                    s = mid + 1;
                }
                else e = mid - 1;
            }
            else{
                if(tar < nums[mid] && tar >= nums[s]){
                    e = mid - 1;
                }
                else s = mid + 1;
            }
        }

        return false;
    }
};