class Solution {
public:
    bool sol(long long mid , vector<pair<long long , long long>>& arr){
        long long n = arr.size();
        for(long long i=0 ; i<n ; i++){
            if(arr[i].second > mid) return false;
            else{
                mid = max(0LL , mid - arr[i].first);
            }
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monster, vector<vector<int>>& add) {
        long long n = monster.size() , m = add.size() , sum = 0 , reduction = 0;
        
        vector<long long> diff(n + 1 , 0);
        for(long long i=0 ; i<m ; i++){
            long long l = add[i][0] , r = add[i][1] , sub = add[i][2];
            
            diff[l] += sub;

            if(r + 1 < n) diff[r + 1] -= sub;
        }

        vector<pair<long long , long long>> arr(n);
        for(long long i=0 ; i<n ; i++){
            reduction += diff[i];

            arr[i].first = monster[i];
            arr[i].second = max(0LL , (long long)monster[i] - reduction);

            sum += monster[i];
        }

        // for(long long i=0 ; i<n ; i++){
        //     cout<<"first : "<<arr[i].first<<" second : "<<arr[i].second<<endl;
        // }

        long long s = 0 , e = sum , ans = 0;
        while(s <= e){
            long long mid = s + (e - s) / 2;

            if(sol(mid , arr)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }

        return ans;
    }
};