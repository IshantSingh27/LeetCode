class Solution {
public:
    string trafficSignal(int x) {
        if(x == 0) return "Green";
        else if(x == 30) return "Orange";
        else if(x > 30 && x <= 90) return "Red";
        else return "Invalid";
    }
};