class Solution {
public:
    bool isP(int val) {
        if (val <= 1) return false;
        if (val <= 3) return true;
        if (val % 2 == 0 || val % 3 == 0) return false;
        for (int idx = 5; idx * idx <= val; idx += 6) {
            if (val % idx == 0 || val % (idx + 2) == 0) return false;
        }
        return true;
    }

    int get(int num) {
        if (num <= 1) return 2;
        int res = num + 1;
        if (res % 2 == 0) res++;
        while (!isP(res)) {
            res += 2;
        }
        return res;
    }

    int evn(int cur) {
        if (cur == 1) return 1;
        if (!isP(cur)) {
            return get(cur) - cur;
        }
        return 0;
    }

    int odd(int cur) {
        if (cur == 2) return 2;
        if (isP(cur)) return 1;
        return 0;
    }

    int minOperations(vector<int>& arr) {
        int len = arr.size();
        int tot = 0;

        for (int ptr = 0; ptr < len; ptr++) {
            if (ptr % 2 == 0) {
                tot += evn(arr[ptr]);
            } else {
                tot += odd(arr[ptr]);
            }
        }

        return tot;
    }
};