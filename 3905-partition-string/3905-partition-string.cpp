class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
    vector<string> result;
    string curr = "";

    for (char c : s) {
        curr += c;
        if (seen.count(curr)) continue;
        result.push_back(curr);
        seen.insert(curr);
        curr = "";
    }

    return result;
    }
};