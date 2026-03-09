// class Solution {
// public:
//     string frequencySort(string s) {
//         vector<pair<int , char>> arr(128);

//         for(int i = 0; i < 128; i++)
//             arr[i] = {0, char(i)};

//         for(char c : s)
//             arr[c].first++;

//         sort(arr.rbegin(), arr.rend());

//         string ans;
//         int i = 0;

//         while(i < 128 && arr[i].first != 0){
//             ans.append(arr[i].first, arr[i].second);
//             i++;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128 , 0);
        int n = s.size();

        for(char c : s){
            freq[c]++;
        }

        vector<vector<char>> buc(n + 1);
        for(int i=0 ; i<128 ; i++){
            if(freq[i] > 0) buc[freq[i]].push_back(char(i));
        }

        string ans;
        for(int i=n ; i>=1 ; i--){
            for(char c : buc[i]){
                ans.append(i , c);
            }
        }

        return ans;
    }
};