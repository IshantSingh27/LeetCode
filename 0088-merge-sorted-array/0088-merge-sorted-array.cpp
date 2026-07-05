class Solution {
public:
void sol(vector<int>& nums1, vector<int>& nums2, int left , int right){
    if(nums1[left] > nums2[right]){
        swap(nums1[left] , nums2[right]);
    }
}
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int gap = (n + m) / 2 + (n + m) % 2;
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < n + m){
                if(left < n && right >= n){
                    sol(nums1 , nums2 , left , right - n);
                }
                else if(left >= n){
                    sol(nums2 , nums2 , left - n , right - n);
                }
                else{
                    sol(nums1 , nums1 , left , right);
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for(int i=n ; i<n + m ; i++){
            nums1[i] = nums2[i - n];
        }
    }
};