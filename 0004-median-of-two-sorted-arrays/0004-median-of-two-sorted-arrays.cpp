class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0 , n = nums1.size() , m = nums2.size() , cnt = 0;
        int med = n + m , t1 = 0;
        double ans;
        if((n + m) % 2 == 0){
            t1 = (n + m) / 2;
        }
        else{
            t1 = ((n + m) + 1) / 2;
        }
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                cnt++;
                if(cnt == t1){
                    ans = nums1[i];
                    i++;
                    break;
                }
                i++;
            }
            else if(nums1[i] >= nums2[j]){
                cnt++;
                if(cnt == t1){
                    ans = nums2[j];
                    j++;
                    break;
                }
                j++;
            }
        }
        if(cnt != t1){
            while(i < n){
                cnt++;
                if(cnt == t1){
                    ans = nums1[i];
                    i++;
                    break;
                }
                i++;
            }
            while(j < m){
                cnt++;
                if(cnt == t1){
                    ans = nums2[j];
                    j++;
                    break;
                }
                j++;
            }
        }

        if((n + m) % 2 == 0){
            double cur = 0;
            if(i < n && j < m && nums1[i] <= nums2[j]){
                cur = nums1[i];
            }
            else if(i < n && j < m && nums1[i] > nums2[j]){
                cur = nums2[j];
            }
            else if(i < n) cur = nums1[i];
            else cur = nums2[j];

            double res = (cur + ans) / 2;
            return res;
        }
        else{
            return ans;
        }
    }
};