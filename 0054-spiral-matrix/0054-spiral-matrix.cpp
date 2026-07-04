class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int n = arr.size() , m = arr[0].size() , top = 0 , left = 0 , right = m - 1 , bottom = n - 1;
        while(top <= bottom && left <= right){
            for(int i=left ; i<=right ; i++){
                ans.push_back(arr[top][i]);
            }
            top++;
            if(top > bottom) break;
            for(int i=top ; i<=bottom ; i++){
                ans.push_back(arr[i][right]);
            }
            right--;
            if(left > right) break;
            for(int i=right ; i>=left ; i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
            if(top > bottom) break;
            for(int i=bottom ; i>=top ; i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
        return ans;
    }
};