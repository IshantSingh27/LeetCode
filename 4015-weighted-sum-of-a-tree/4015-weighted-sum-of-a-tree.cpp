class Solution {
public:
    long long sol(long long node , vector<long long>& depth , vector<int>& parent){
        if(parent[node] == -1) return depth[node] = 1;

        if(depth[node] != -1) return depth[node];

        return depth[node] = 1 + sol(parent[node] , depth , parent);
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        long long h = 1 , n = parent.size() , sum = 0;
        vector<long long> depth(n , -1);

        for(long long i=0 ; i<n ; i++){
            h = max(h , sol(i , depth , parent));
        }
        h++;

        for(long long i=0 ; i<n ; i++){
            cout<<depth[i]<<" | ";
        }
        cout<<endl;

        for(long long i=0 ; i<n ; i++){
            sum += 1LL * nums[i] * (h - depth[i]);
        }

        return sum;
    }
};