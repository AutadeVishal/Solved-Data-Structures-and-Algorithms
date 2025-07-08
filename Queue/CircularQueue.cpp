#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int * arr;
    int front;
    int rear;
    int size;
    CircularQueue(int n){
        size=n;
        front=-1;
        rear=-1;
        arr=new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((rear+1)%size==front) return false;//full saathi
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1) return -1;
        if(front==rear){
            int value=arr[front];
            front=rear=-1;
            return value;
        }
        int value=arr[front];
        front=(front+1)%size;
        return value;
        // Write your code here.
    }
};
