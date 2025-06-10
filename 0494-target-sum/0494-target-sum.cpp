class Solution {
public:
    int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
	for(int i=0 ; i<n ; i++){
		totsum += arr[i];
	}
	if (totsum < abs(d) || (totsum - d) % 2 != 0) return 0;
	int sum = (totsum + d) / 2;
	vector<int> prev(sum + 1 , 0) , cur(sum + 1 , 0);

	if(arr[0] == 0) prev[0] = 2;
	else prev[0] = 1;
	if(arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;
	for(int ind = 1 ; ind < n ; ind++){
		for(int tar = 0 ; tar <= sum ; tar++){
			int notTake = prev[tar];
			int take = 0;
			if(arr[ind] <= tar) take = prev[tar - arr[ind]];
			cur[tar] = (take + notTake);
		}
		prev = cur;
	}
	return prev[sum];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n , target , nums);
    }
};