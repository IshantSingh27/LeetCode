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
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n = arr.size();
        disjointSet ds(n);
        unordered_map<string , int> mp;
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<arr[i].size() ; j++){
                string mail = arr[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionBySize(i , mp[mail]);
                }
            }
        }

        vector<vector<string>> merger(n);
        for(auto it : mp){
            string mail = it.first;
            int ind = ds.find(it.second);

            merger[ind].push_back(mail);
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