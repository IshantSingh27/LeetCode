class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() , extra = 0 , req = 0 , sind = 0;
        
        for(int i=0 ; i<n ; i++){
            extra += gas[i] - cost[i];

            if(extra < 0){
                sind = i + 1;
                req += extra;
                extra = 0;
            }
        }

        if(req + extra >= 0) return sind;
        else return -1;
    }
};