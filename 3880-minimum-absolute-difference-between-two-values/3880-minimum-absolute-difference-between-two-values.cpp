class Solution {
public:
    int minAbsoluteDifference(vector<int>& arr) {
        vector<int> a , b;
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] == 1) a.push_back(i);
            else if(arr[i] == 2) b.push_back(i);
        }

        sort(a.begin() , a.end());
        sort(b.begin() , b.end());

        if(a.size() == 0 || b.size() == 0) return -1;

        int i = 0 , j = 0 , n = a.size() , m = b.size() , ans = 1e9;
        while(i < n && j < m){
            ans = min(ans , abs(a[i] - b[j]));

            if(a[i] > b[j]){
                j++;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};