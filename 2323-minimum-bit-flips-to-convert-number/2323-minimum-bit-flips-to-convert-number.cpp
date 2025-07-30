class Solution {
public:
    int minBitFlips(int s, int g) {
        int num = s ^ g;

        int cnt = 0;
        // for(int i=0 ; i<=31 ; i++){
        //     if( (num & (1 << i)) != 0){
        //         cnt++;
        //     }
        // }
        while(num > 0){
            if(num % 2 == 1) cnt++;
            num = num / 2;
        }

        return cnt;
    }
};