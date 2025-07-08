#include <bits/stdc++.h> 
class Queue {
public:
int arr[5000];
int r,f;
    Queue() {
        r=-1;
        f=-1;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (f==-1);

        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        if(f==-1){
            f=r=0;
            arr[r]=data;
        }
else{
    arr[++r]=data;
}
        // Implement the enqueue() function
    }

    int dequeue() {
        if(f==-1)return -1;
        else{
            int data=arr[f++];
            if(f>r){
                f=r=-1;
            }
            return data;
        }
        // Implement the dequeue() function
    }

    int front() {
        return (f==-1)? -1: arr[f];
        // Implement the front() function
    }
};
