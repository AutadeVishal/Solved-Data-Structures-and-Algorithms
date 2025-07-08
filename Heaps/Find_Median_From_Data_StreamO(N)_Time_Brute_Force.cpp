class MedianFinder {
public:
vector<double>arr;
int size;
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        int i=size-1;
        arr.push_back(num);
        size++;
        while(i>=0 && arr[i+1]>arr[i])
        {
             swap(arr[i],arr[i+1]);
             i--;
        }
    }
    
    double findMedian() {
        if(size!=0 && size%2==0){
            return (arr[size/2]+arr[(size-1)/2])/2;
        }
        else{
          if(size!=0)  return arr[size/2];
          else return NULL;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
