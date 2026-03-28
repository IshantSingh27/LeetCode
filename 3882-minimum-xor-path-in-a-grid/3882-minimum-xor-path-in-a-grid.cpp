class Solution {
public:
    int minCost(vector<vector<int>>& grd) {
        int n = grd.size(), m = grd[0].size();

        queue<tuple<int,int,int>> q;
        q.push({0,0,grd[0][0]});

        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(1024, false)));
        vis[0][0][grd[0][0]] = true;

        int ans = INT_MAX;

        vector<int> dr = {1,0};
        vector<int> dc = {0,1};

        while(!q.empty()){
            auto [r,c,x] = q.front();
            q.pop();

            if(r==n-1 && c==m-1){
                ans = min(ans, x);
                continue;
            }

            for(int i=0;i<2;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr<n && nc<m){
                    int nx = x ^ grd[nr][nc];

                    if(!vis[nr][nc][nx]){
                        vis[nr][nc][nx] = true;
                        q.push({nr,nc,nx});
                    }
                }
            }
        }

        return ans;
    }
};