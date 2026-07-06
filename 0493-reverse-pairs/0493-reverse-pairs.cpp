class Solution {
public:
    int merger(vector<int>& arr, int l, int mid, int r){
        int cnt = 0;
        int right = mid + 1;
        for(int i=l ; i<=mid ; i++){
            while(right <= r && (long long)arr[i] > (2LL * arr[right])){
                right++;
            }
            cnt += right - (mid + 1);
        }

        vector<int> temp;
        int left = l;
        right = mid + 1;
        while(left <= mid && right <= r){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= r){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=l ; i<=r ; i++){
            arr[i] = temp[i - l];
        }
        
        return cnt;
    }
    int sol(vector<int>& arr, int l, int r){
        if(l >= r) return 0;
        int mid = l + (r - l) / 2;
        int cnt = 0;
        
        cnt += sol(arr , l , mid);
        cnt += sol(arr , mid + 1 , r);
        cnt += merger(arr , l , mid , r);

        return cnt;
    }
    int reversePairs(vector<int>& arr) {
        return sol(arr , 0 , arr.size() - 1);
    }
};