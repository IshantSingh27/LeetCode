class disjointSet{
public:
    vector<int> rank , parent , size;

    disjointSet(int n){
        rank.resize(n + 1 , 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void unionByRank(int x , int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;
        if(rank[px] < rank[py]){
            parent[px] = py;
        }
        else if(rank[py] < rank[px]){
            parent[py] = px;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
    }

    void unionBySize(int x , int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;
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
        disjointSet ds(n);

        int cntex = 0;
        for(auto it : arr){
            int u = it[0];
            int v = it[1];
            if(ds.find(u) == ds.find(v)){
                cntex++;
            }
            else{
                ds.unionBySize(u , v);
            }
        }

        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(ds.parent[i] == i){
                ans++;
            }
        }

        if(ans - 1 <= cntex){
            return ans - 1;
        }
        else return -1;
    }
};