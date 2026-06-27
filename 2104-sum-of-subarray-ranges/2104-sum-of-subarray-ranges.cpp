class Solution {
public:
    // Next Smaller Element (<=)
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Previous Smaller Element (<)
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Next Greater Element (>=)
    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Previous Greater Element (>)
    vector<int> prevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> next = nextSmaller(arr);
        vector<int> prev = prevSmaller(arr);

        long long ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans += left * right * 1LL * arr[i];
        }

        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> next = nextGreater(arr);
        vector<int> prev = prevGreater(arr);

        long long ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans += left * right * 1LL * arr[i];
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};