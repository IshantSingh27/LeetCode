class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int a , b , n = arr.size() , cnta = 0 , cntb = 0;
        for(int i=0 ; i<n ; i++){
            if(cnta == 0 && arr[i] != b){
                cnta++;
                a = arr[i];
            }
            else if(arr[i] == a) cnta++;
            else if(cntb == 0){
                cntb++;
                b = arr[i];
            }
            else if(arr[i] == b) cntb++;
            else{
                cnta--;
                cntb--;
            }
        }
        cnta = 0;
        cntb = 0;
        for(int i=0 ; i<n ; i++){
            if(arr[i] == a) cnta++;
            else if(arr[i] == b) cntb++;
        }
        if(cnta > n / 3 && cntb > n / 3) return {a , b};
        else if(cnta > n / 3) return {a};
        else if(cntb > n / 3) return {b};
        else return {};
    }
};