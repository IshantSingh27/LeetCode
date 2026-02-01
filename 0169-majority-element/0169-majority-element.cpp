class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt1 = 0 , ele1 = 0 , n = nums.size();

        for(int i=0 ; i < n ; i++){
            if(cnt1 == 0){
                ele1 = nums[i];
                cnt1++;
            }
            else if(nums[i] == ele1) cnt1++;
            else cnt1--;
        }

        cnt1 = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == ele1) cnt1++;
        }

        // cout<<"cnt : "<<cnt1<<endl;

        if(cnt1 > n / 2) return ele1;
        else return -1;
    }
};