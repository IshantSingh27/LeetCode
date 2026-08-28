class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        vector<int> freq(26 , 0);

        for(auto it : arr){
            freq[it - 'A']++;
        }

        int maxfreq = 0;
        for(auto it : freq){
            maxfreq = max(maxfreq , it);
        }

        int countmax = 0;
        for(auto it : freq){
            if(it == maxfreq) countmax++;
        }

        return max((int)arr.size() , ((maxfreq - 1) * (n + 1)) + countmax);
    }
};