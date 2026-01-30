class Solution {
public:
    long long pickGifts(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for(auto it : arr) pq.push(it);
        long long ans = 0;

        for(int i=0 ; i<k ; i++){
            int gift = pq.top();
            pq.pop();
            pq.push(sqrt(gift));
        }

        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};