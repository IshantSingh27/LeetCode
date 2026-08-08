class Solution {
public:
    int maximumWidth(vector<int>& arr) {
        sort(arr.begin() , arr.end());

        unordered_map<int , int> freq;
        for(auto x : arr){
            freq[x]++;
        }

        vector<int> val;
        for(auto& [x , f] : freq){
            val.push_back(x);
        }

        int n = val.size();
        unordered_map<int , int> paircount;
        for(int i=0 ; i<n ; i++){
            int x = val[i];

            paircount[x + x] += freq[x] / 2;

            for(int j=i+1 ; j<n ; j++){
                int y = val[j] , h = x + y;

                int cur = min(freq[x] , freq[y]);
                
                paircount[h] += cur;
            }
        }

        int ans = 0;

        for(auto& [x , f] : freq){
            int cur = paircount[x];

            ans = max(ans , cur + f);
        }

        for(auto& [x , f] : paircount){
            ans = max(ans , f);
        }

        return ans;
    }
};