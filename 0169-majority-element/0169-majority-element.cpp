class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size() , cur = 0 , cnt = 0;
        for(int i=0 ; i<n ; i++){
            if(cnt == 0){
                cur = arr[i];
                cnt++;
            }
            else if(arr[i] == cur){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return cur;
    }
};