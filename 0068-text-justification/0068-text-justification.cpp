class Solution {
public:
    vector<string> fullJustify(vector<string>& arr, int len) {
        int n = arr.size(), i = 0;
        vector<string> ans;

        while (i < n) {
            int j = i, chars = 0;

            while (j < n && chars + arr[j].size() + (j - i) <= len) {
                chars += arr[j].size();
                j++;
            }

            int words = j - i;
            int gaps = words - 1;
            int space = len - chars;
            string line;

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += arr[k];
                    if (k != j - 1) line += ' ';
                }
                line += string(len - line.size(), ' ');
            } 
            else {
                int base = space / gaps;
                int extra = space % gaps;

                for (int k = i; k < j; k++) {
                    line += arr[k];
                    if (k != j - 1) {
                        line += string(base + (extra-- > 0), ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
