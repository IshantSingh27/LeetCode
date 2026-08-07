class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        long long n = tasks.size() , m = shifts.size();
        vector<long long> prefix(n + 1 , 0);
        for(long long i=0 ; i<n ; i++){
            prefix[i + 1] = prefix[i] + tasks[i];
        }

        long long progress= 0;
        vector<int> ans;
        for(long long i=0 ; i<m ; i++){
            progress += shifts[i];

            if(progress >= prefix[n]){
                ans.push_back(0);
                progress = 0;
                continue;
            }
            
            long long idx = upper_bound(prefix.begin() , prefix.end() , progress) - prefix.begin() - 1;

            ans.push_back(n - idx);
        }

        return ans;
    }
};