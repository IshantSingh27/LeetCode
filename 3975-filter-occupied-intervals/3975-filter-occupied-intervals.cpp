class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& arr, int fs, int fe) {
        if(arr.empty()) return {};

        sort(arr.begin() , arr.end());
        vector<vector<int>> merge;
        merge.push_back(arr[0]);

        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i][0] - 1 <= merge.back()[1]){
                merge.back()[1] = max(merge.back()[1] , arr[i][1]);
            }
            else merge.push_back(arr[i]);
        }

        vector<vector<int>> ans;
        for(auto it : merge){
            if(it[0] > fe || it[1] < fs) {
                ans.push_back(it);
                continue;
            }

            if(it[0] < fs){
                ans.push_back({it[0] , fs - 1});
            }
            
            if(it[1] > fe){
                ans.push_back({fe + 1 , it[1]});
            }
        }

        return ans;
    }
};