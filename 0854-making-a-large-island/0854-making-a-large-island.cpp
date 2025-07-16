class disjoint{
  public:
    vector<int> size , parent;
    
    disjoint(int n){
        size.resize(n + 1 , 1);
        parent.resize(n + 1 , 0);
    
        for(int i=0 ; i<n ; i++) parent[i] = i;
    }
    
    int find(int x){
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }
    
    void unionBySize(int x , int y){
        int px = find(x);
        int py = find(y);
        if(parent[px] == parent[py]) return;
        if(size[px] < size[py]){
            parent[px] = py;
            size[py] += size[px];
        }
        else{
            parent[py] = px;
            size[px] += size[py];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& arr) {
        int n = arr.size() , ans = 0;
        disjoint ds(n * n);
        for(int row=0 ; row<n ; row++){
            for(int col=0 ; col<n ; col++){
                if(arr[row][col] == 0) continue;
                
                vector<int> drow = {-1 , 0 , 1 , 0};
                vector<int> dcol = {0 , 1 , 0 , -1};

                for(int i=0 ; i<4 ; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && arr[nrow][ncol] == 1){
                        int num = (row * n) + col;
                        int adjnum = (nrow * n) + ncol;

                        if (ds.find(num) != ds.find(adjnum)) {
                            ds.unionBySize(num, adjnum);
                        }
                    }
                }
            }
        }

        for(int row=0 ; row<n ; row++){
            for(int col=0 ; col<n ; col++){
                if(arr[row][col] == 1) continue;
                
                vector<int> drow = {-1 , 0 , 1 , 0};
                vector<int> dcol = {0 , 1 , 0 , -1};

                set<int> sz;
                for(int i=0 ; i<4 ; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && arr[nrow][ncol] == 1){
                        int adjnum = (nrow * n) + ncol;
                        sz.insert(ds.find(adjnum));
                    }
                }

                int maxi = 0;
                for(auto it : sz){
                    maxi += ds.size[it];
                }

                ans = max(ans , maxi + 1);
            }
        }

        for(int i=0 ; i<(n * n) ; i++){
            ans = max(ans , ds.size[ds.find(i)]);
        }

        return ans;
    }
};