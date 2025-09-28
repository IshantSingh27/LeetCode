class Solution {
public:
    vector<int> gen(int row){
        vector<int> ans;
        ans.push_back(1);

        int cur = 1;
        for(int col=1 ; col<row ; col++){
            cur = cur * (row - col);
            cur = cur / col;
            ans.push_back(cur);
        }

        return ans;
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        for(int i=1 ; i<=n ; i++){
            ans.push_back(gen(i));
        }

        return ans;
    }
};