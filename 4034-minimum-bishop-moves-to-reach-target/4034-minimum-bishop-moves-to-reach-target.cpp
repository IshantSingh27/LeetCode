class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        if(s[0] == t[0] && s[1] == t[1]) return 0;
        if(abs(s[0] - t[0]) == abs(s[1] - t[1])) return 1;

        if((s[0] % 2 == 0 && s[1] % 2 == 0) || (s[0] % 2 == 1 && s[1] % 2 == 1)){
            // cout<<"here"<<endl;
            if((t[0] % 2 == 0 && t[1] % 2 == 0) || (t[0] % 2 == 1 && t[1] % 2 == 1)) return 2;
            else return -1;
        }
        else{
            cout<<"here"<<endl;
            if((t[0] % 2 == 1 && t[1] % 2 == 0) || (t[0] % 2 == 0 && t[1] % 2 == 1)) return 2;
            else return -1;
        }
    }
};