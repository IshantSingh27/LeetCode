class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n > m)
            return false;

        const int INF = m + 1;

        // nxt[i][c] = first position >= i
        // where character c occurs in t
        vector<vector<int>> nxt(m + 1, vector<int>(26, INF));

        for (int i = m - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][t[i] - 'a'] = i;
        }

        // Position in t after matching s prefix
        // without replacement / with replacement
        int p0 = 0;
        int p1 = 0;

        for (char c : s) {

            int x = c - 'a';

            // -------------------------
            // Don't use replacement
            // -------------------------
            int pos0 = INF;

            if (p0 < m) {
                int idx = nxt[p0][x];

                if (idx < m)
                    pos0 = idx + 1;
            }

            // -------------------------
            // Already used replacement
            // OR use replacement now
            // -------------------------

            // Case 1:
            // replacement was already used,
            // so current character must match normally.
            int exact = INF;

            if (p1 < m) {
                int idx = nxt[p1][x];

                if (idx < m)
                    exact = idx + 1;
            }

            // Case 2:
            // Use replacement on current character.
            //
            // We can change s[i] into ANY character,
            // so change it into t[p0].
            int replace = INF;

            if (p0 < m)
                replace = p0 + 1;

            int pos1 = min(exact, replace);

            p0 = pos0;
            p1 = pos1;
        }

        // Either we succeeded without replacement
        // or with one replacement.
        return p0 <= m || p1 <= m;
    }
};