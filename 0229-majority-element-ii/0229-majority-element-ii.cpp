class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int cnt1 = 0 , cnt2 = 0 , ele1 , ele2 , n = arr.size();

        for(int i=0 ; i<n ; i++){
            if(cnt1 == 0 && arr[i] != ele2){
                ele1 = arr[i];
                cnt1++;
            }
            else if(cnt2 == 0 && arr[i] != ele1){
                ele2 = arr[i];
                cnt2++;
            }
            else if(arr[i] == ele1){
                cnt1++;
            }
            else if(arr[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }

            // cout<<ele1<<" | "<<ele2<<endl;
        }

        cnt1 = 0 , cnt2 = 0;
        for(int i=0 ; i<n ; i++){
            if(arr[i] == ele1) cnt1++;
            else if(arr[i] == ele2) cnt2++;
        }
        if(cnt1 > n/3 && cnt2 > n/3) return {ele1 , ele2};
        else if(cnt1 > n/3) return {ele1};
        else if(cnt2 > n/3) return {ele2};
        else return {};
    }
};