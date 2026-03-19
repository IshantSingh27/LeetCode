class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;

        for(int x : arr){
            bool dest = false;
            while(!ans.empty() && x < 0 && ans.back() > 0){
                if(ans.back() < -x){
                    ans.pop_back();
                    continue;
                }
                else if(ans.back() == -x){
                    ans.pop_back();
                }

                dest = true;
                break;
            }

            if(!dest) ans.push_back(x);
        }

        return ans;
    }
};