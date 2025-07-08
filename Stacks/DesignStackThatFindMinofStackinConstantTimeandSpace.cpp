class SpecialStack {
    public:
        int min=INT_MAX;
         vector<int> arr ;
    void push(int data) {
        if(arr.empty() ){
            min=data;
            arr.push_back(data);

        }
        else{
            if (data< min) {
              int val = 2 * data - min;
              min = data;
              arr.push_back(val);
            }
            else{
                arr.push_back(data);
            }
        }
    }

    void pop() {
        if(!arr.empty() ){
            if (arr.back() < min) {
                min = 2 * min - arr.back();
                arr.pop_back();
            }
            else{
                arr.pop_back();
            }
        }
    }

    int top() {
        if(arr.empty()) return -1;
        
            if (arr.back() < min) {
               return  min;
            
            }
            return arr.back();
        
    }

    int getMin() {
        return min;
    }  
};
