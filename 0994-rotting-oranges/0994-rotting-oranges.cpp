class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size() , fresh = 0 , cnt = 0 , ans = 0;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        queue<pair<pair<int , int> , int>> q;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 2){
                    q.push({{i , j} , 0});
                    vis[i][j] = 2;
                }
                if(arr[i][j] == 1) fresh++;
            }
        }

        vector<int> drow = {-1 , 0 , 1 , 0};
        vector<int> dcol = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            ans = max(ans , time);
            q.pop();

            for(int k=0 ; k<4 ; k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && arr[nrow][ncol] != 0){
                    q.push({{nrow , ncol} , time + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        cout<<"fresh : "<<fresh<<" cnt : "<<cnt<<endl;

        if(cnt == fresh) return ans; 
        else return -1;
    }
};