class Solution {
public:
    vector<int> nextsmall(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> prevsmall(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextsmall(arr);
        vector<int> pse = prevsmall(arr);

        long long tot = 0;
        int n = arr.size();

        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            tot += left * right * arr[i];
        }

        return tot;
    }

    vector<int> nextgreat(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();

            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> prevgreat(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nge = nextgreat(arr);
        vector<int> pge = prevgreat(arr);

        long long tot = 0;
        int n = arr.size();

        for(int i=0;i<n;i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            tot += left * right * arr[i];
        }

        return tot;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};