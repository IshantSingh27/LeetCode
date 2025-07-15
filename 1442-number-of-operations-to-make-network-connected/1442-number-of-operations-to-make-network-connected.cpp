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
    int makeConnected(int n, vector<vector<int>>& arr) {
        disjoint ds(n);
        int cnte = 0 , cntc = 0;
        for(auto it : arr){
            int u = it[0];
            int v = it[1];
            if(ds.find(u) == ds.find(v)) cnte++;
            else ds.unionBySize(u , v);
        }

        for(int i=0 ; i<n ; i++){
            if(ds.parent[i] == i) cntc++;
        }

        if(cnte >= cntc - 1) return cntc - 1;
        else return -1;
    }
};