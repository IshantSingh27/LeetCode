class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        long long n = nums.size() , sum = 0 , h = 1;
        vector<long long> depth(n , 0);

        for(long long i=0 ; i<n ; i++){
            if(depth[i] != 0) continue;

            vector<long long> path;
            long long j = i;
            while(depth[j] == 0 && parent[j] != -1){
                path.push_back(j);
                j = parent[j];
            }

            if(parent[j] == -1 && depth[j] == 0) depth[j] = 1;

            for(long long k=path.size() - 1 ; k>=0 ; k--){
                depth[path[k]] = depth[parent[path[k]]] + 1;
            }

            h = max(h , depth[i]);
        }
        h++;

        for(long long i=0 ; i<n ; i++){
            sum += 1LL * nums[i] * (h - depth[i]);
        }

        return sum;
    }
};