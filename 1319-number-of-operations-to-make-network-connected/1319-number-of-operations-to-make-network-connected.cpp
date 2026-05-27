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
    int makeConnected(int n, vector<vector<int>>& adj) {
        disjoint ds(n);
        int cntex = 0 , cnt = 0;
        for(auto it : adj){
            if(ds.find(it[0]) == ds.find(it[1])){
                cntex++;
            }
            else{
                ds.unionbysize(it[0] , it[1]);
            }
        }
        for(int i=0 ; i<n ; i++){
            if(ds.find(i) == i) cnt++;
        }
        if(cnt - 1 > cntex) return -1;
        else return cnt - 1;
    }
};