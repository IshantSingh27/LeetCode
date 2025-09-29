class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int cnt1 = 0 , cnt2 = 0 , el1 = INT_MIN , el2 = INT_MIN , n = arr.size();

        for(int i=0 ; i<n ; i++){
            if(cnt1 == 0 && arr[i] != el2){
                el1 = arr[i];
                cnt1 += 1;
            }
            else if(cnt2 == 0 && el1 != arr[i]){
                el2 = arr[i];
                cnt2 += 1;
            }
            else if(arr[i] == el1){
                cnt1++;
            }
            else if(arr[i] == el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0; cnt2 = 0;
        for(int i=0 ; i<n ; i++){
            if(el1 == arr[i]) cnt1++;
            else if(el2 == arr[i]) cnt2++;
        }

        if(cnt1 > n / 3 && cnt2 > n / 3) return {el1 , el2};
        else if(cnt1 > n / 3) return {el1};
        else if(cnt2 > n / 3) return {el2};
        else return {};
    }
};