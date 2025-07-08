#include <bits/stdc++.h> 
class NQueue{
public:
    // Initialize your data structure.
    int *next;
    int *front;
    int * rear;
    int freenode;
    int * store;
    NQueue(int n, int s){
        // Write your code here.
        store=new int[s];
        next=new int[s];
        for(int i=0;i<s-1;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
        front=new int[n];
        for(int i=0;i<n;i++) front[i]=-1;
        rear=new int[n];
        for(int i=0;i<n;i++) rear[i]=-1;
        freenode=0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        m--;
        if(freenode==-1){
            return false;
        }
        int index=freenode;
        freenode=next[freenode];
            store[index]=x;
            if(front[m]==-1){
                front[m]=rear[m]=index;
                next[index]=-1;
            }
            else{
                next[rear[m]]=index;
                rear[m]=index;

                next[index]=-1;
               
            }
         return true;

    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        m--;
        // Write your code here.
        if(front[m]==-1) return -1;
        int index=front[m];
        front[m]=next[index];
        next[index]=freenode;
        freenode=index;
        return store[freenode];
    }
};
