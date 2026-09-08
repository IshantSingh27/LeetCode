class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int , vector<int> , greater<int>> minq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxq.size() == 0){
            maxq.push(num);
            return;
        }
        else if(minq.size() == 0){
            if(num > maxq.top()) minq.push(num);
            else{
                minq.push(maxq.top());
                maxq.pop();
                maxq.push(num);
            }
            return;
        }

        if(num < maxq.top()){
            maxq.push(num);
            if(maxq.size() > minq.size() + 1){
                int node = maxq.top();
                maxq.pop();
                minq.push(node);
            }
        }
        else{
            minq.push(num);
            if(minq.size() > maxq.size() + 1){
                int node = minq.top();
                minq.pop();
                maxq.push(node);
            }
        }
    }
    
    double findMedian() {
        if(maxq.size() > minq.size()){
            return (double)maxq.top();
        }
        else if(minq.size() > maxq.size()){
            return (double)minq.top();
        }
        else{
            return ( (double)(maxq.top()) + (double)(minq.top()) ) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */