class Solution {
public:
    vector<int> gen(int row){
        vector<int> ans;
        ans.push_back(1);

        int cur = 1;
        for(int col=1 ; col<row - 1; col++){
            cout<<col<<endl;
            cur = cur * (row - col);
            cur = cur / col;

            ans.push_back(cur);
        }

        ans.push_back(1);
        return ans;
    }
    // vector<vector<int>> generate(int row) {
    //     vector<vector<int>> ans;
    //     ans.push_back({1});

    //     for(int i=2 ; i<=row ; i++){
    //         ans.push_back(gen(i));
    //     }

    //     return ans;
    // }
    vector<vector<int>> generate(int row) {
        vector<vector<int>> ans;
        
        for(int i=0 ; i<row ; i++){
            vector<int> cur(i + 1 , 1);
            for(int j=1 ; j<i ; j++){
                cur[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(cur);
        }

        return ans;
    }
};