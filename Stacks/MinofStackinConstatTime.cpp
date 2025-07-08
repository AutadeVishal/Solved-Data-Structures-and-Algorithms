class SpecialStack {
    public:
        vector<int>* arr = new vector<int>();
        vector<int>* min = new vector<int>();
    void push(int data) {
       arr->push_back(data);
       int a;
       if (min->empty()) {
          a = data;
       }
    else{
        a=min->back();
        a=(a<data)? a:data;
    }
       
       min->push_back(a);
    }

    void pop() {
        arr->pop_back();
        min->pop_back();
    }

    int top() {
        return arr->back();
    }

    int getMin() {
        return min->back();
    }  
};
