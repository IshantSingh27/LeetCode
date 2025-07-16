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
    int removeStones(vector<vector<int>>& arr) {
        int maxr = 0;
        int maxc = 0;
        for(auto it : arr){
            maxr = max(maxr , it[0]);
            maxc = max(maxc , it[1]);
        }

        disjoint ds(maxr + maxc + 2);
        unordered_map<int , int> mp;

        for(auto it : arr){
            int row = it[0];
            int col = it[1] + maxr + 1;

            ds.unionBySize(row , col);
            mp[row] = 1;
            mp[col] = 1;
        }

        int cnt = 0;
        for(auto it : mp){
            if(ds.find(it.first) == it.first){
                cnt++;
            }
        }

        return arr.size() - cnt;
    }
};