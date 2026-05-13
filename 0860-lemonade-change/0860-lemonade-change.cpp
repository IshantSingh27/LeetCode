class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int n = arr.size() , five = 0 , ten  = 0;
        bool pos = true;
        for(int i=0 ; i<n ; i++){
            if(arr[i] == 5){
                five++;
            }
            else if(arr[i] == 10){
                if(five > 0){
                    five--;
                    ten++;
                }
                else{
                    pos = false;
                    break;
                }
            }
            else{
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    pos = false;
                    break;
                }
            }
        }

        return pos;
    }
};