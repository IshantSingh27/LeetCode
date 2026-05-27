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
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n = arr.size();
        unordered_map<string , int> mp;
        disjoint ds(n + 1);
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<arr[i].size() ; j++){
                string mail = arr[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionbysize(mp[mail] , i);
                }
            }
        }
        vector<vector<string>> merger(n);
        for(auto it : mp){
            int ind = ds.find(it.second);
            merger[ind].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0 ; i<n ; i++){
            if(merger[i].size() == 0) continue;
            sort(merger[i].begin() , merger[i].end());
            vector<string> temp;
            temp.push_back(arr[i][0]);
            for(auto it : merger[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};