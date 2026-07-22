class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int , vector<int> , greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }

        if(left.size() > right.size() + 1){
            int temp = left.top();
            left.pop();
            right.push(temp);
        }
        else if(right.size() > left.size() + 1){
            int temp = right.top();
            right.pop();
            left.push(temp);
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) return double((left.top() + right.top()) / 2.0);
        else if(left.size() > right.size()) return left.top();
        else return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */