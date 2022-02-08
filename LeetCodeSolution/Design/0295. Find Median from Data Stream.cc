

class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> right;
    priority_queue<int> left;
    bool even;
    MedianFinder() {
        even=true;
    }
    
    void addNum(int num) {
        if(even){
            right.push(num);
            left.push(right.top());
            right.pop();
        }else{
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if(even){
            return (left.top()+right.top())/2.0;
        }else{
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
