class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];

        // Check triangle validity
        if (a + b <= c || a + c <= b || b + c <= a)
            return {};

        // Law of Cosines
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));

        // Convert to degrees
        double deg = 180.0 / M_PI;
        A *= deg;
        B *= deg;
        C *= deg;

        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());

        return ans;
    }
};