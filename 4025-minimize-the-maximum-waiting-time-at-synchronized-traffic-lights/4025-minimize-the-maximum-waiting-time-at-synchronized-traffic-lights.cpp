class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arr) {
        //apply binary search and take max element from lights[i] do arrival[j] % period to check
        int maxi = *max_element(lights.begin() , lights.end()) , n = arr.size() , ans = 0;

        for(int i=0 ; i<n ; i++){
            int r = arr[i] % period;
            if(r >= maxi){
                cout<<"add : "<<period - r<<endl;
                ans = max(ans , period - r);
            }
        }

        return ans;
    }
};