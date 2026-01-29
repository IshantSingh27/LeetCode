class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int> pq;
        for(auto it : arr){
            pq.push(it);
        }

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            cout<<"x : "<<x<<" y : "<<y<<endl;

            if(x == y) continue;
            else{
                pq.push(x - y);
            }
        }

        if(pq.size() == 1) return pq.top();
        else return 0;
    }
};