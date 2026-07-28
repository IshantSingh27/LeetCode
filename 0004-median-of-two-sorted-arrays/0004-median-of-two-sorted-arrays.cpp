class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
    int total = n + m;

    int i = 0, j = 0;
    int prev = 0, curr = 0;

    for (int cnt = 0; cnt <= total / 2; cnt++) {
        prev = curr;

        if (i < n && (j >= m || a[i] <= b[j]))
            curr = a[i++];
        else
            curr = b[j++];
    }

    if (total % 2)
        return curr;

    return (prev + curr) / 2.0;
    }
};