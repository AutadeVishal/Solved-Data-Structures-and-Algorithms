class MedianFinder {
public:
priority_queue<int>left;
priority_queue<int,vector<int>,greater<int>>right;
int leftsize;
int rightsize;
    MedianFinder() {
        leftsize=0;
        rightsize=0;
    }
    
    void addNum(int num) {
       if(leftsize==rightsize){
        if(leftsize==0){
            left.push(num);
            leftsize++;
        }
        else {
            if(left.top()<num){
               right.push(num);
               rightsize++;
            }
            else{
               left.push(num);
               leftsize++;
            }
        }
       }

       else if(leftsize>rightsize){
        if(num<left.top()){
            right.push(left.top());
            rightsize++;
            left.pop();
            left.push(num);
        }
        else {
            right.push(num);
            rightsize++;
        }
       }
       else{
        //rightsize>leftsize
        if(num>right.top()){
            left.push(right.top());
            right.pop();
            right.push(num);
           leftsize++;
        }
        else{
            left.push(num);
            leftsize++;
        }
       }
    }
    
    double findMedian() {
        if(leftsize>rightsize){
            return left.top();
        }
        else if(rightsize>leftsize){
            return right.top();
        }
        else if(rightsize==0){
            return left.top();
        }
        else if(leftsize==0) return right.top();
        else{
            return (left.top()+right.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
