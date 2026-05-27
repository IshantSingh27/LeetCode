class disjoint{
    public:
    vector<int> par , size;
    disjoint(int n){
        par.resize(n);
        size.resize(n , 1);
        for(int i=0 ; i<n ; i++){
            par[i] = i;
        }
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unionbysize(int x , int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        else if(size[px] < size[py]){
            size[py] += size[px];
            par[px] = py;
        }
        else{
            size[px] += size[py];
            par[py] =px;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& arr) {
        int maxr = 0 , maxc = 0;
        for(auto it : arr){
            maxr = max(maxr , it[0]);
            maxc = max(maxc , it[1]);
        }
        disjoint ds(maxr + maxc + 2);
        unordered_map<int , int> mp;
        for(auto it : arr){
            int row = it[0];
            int col = it[1] + maxr + 1;
            ds.unionbysize(row , col);
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