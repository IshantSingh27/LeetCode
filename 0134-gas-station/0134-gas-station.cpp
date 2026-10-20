class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() , sum = 0 , sind = -1;
        vector<int> dif(n);

        for(int i=0 ; i<n ; i++){
            sum += gas[i] - cost[i];

            if(sum >= 0 && sind == -1) sind = i;

            if(sum < 0){
                sind = -1;
                sum = 0;
            }
        }

        if(sind == -1) return -1;

        sum = 0;
        for(int i=sind ; i<sind + n ; i++){
            sum += gas[i % n] - cost[i % n];

            // cout<<sum<<endl;

            if(sum < 0){
                return -1;
            }
        }

        return sind;
    }
};