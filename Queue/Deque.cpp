#include <bits/stdc++.h>
class Deque {
public:
  // Initialize your data structure.
  int *arr;
  int front;
  int rear;
  int size;
  Deque(int n) {
      size = n;
    arr = new int[size];
    front = rear = -1;
    
    // Write your code here.
  }

  // Pushes 'X' in the front of the deque. Returns true if it gets pushed into
  // the deque, and false otherwise.
  bool pushFront(int x) {
    if (isFull())
      return false;
    if (isEmpty()) {
      front = rear = 0;
      arr[front] = x;
      return true;
    } else {
      front = (front - 1+size) % size;
      arr[front] = x;
      return true;
    }

    // Write your code here.
  }

  // Pushes 'X' in the back of the deque. Returns true if it gets pushed into
  // the deque, and false otherwise.
  bool pushRear(int x) {
  if(isFull()) return false;
    if (isEmpty()) {
      front = rear = 0;
      arr[rear] = x;
      return true;
    } else {
      rear = (rear + 1) % size;
      arr[rear] = x;
      return true;
    }

    // Write your code here.
  }

  // Pops an element from the front of the deque. Returns -1 if the deque is
  // empty, otherwise returns the popped element.
  int popFront() {
    if (isEmpty())  return -1;
     int val = arr[front];
    if(front==rear){
        front=rear=-1;
        return val;
    }
   
    front = (front + 1) % size;
    return val;
    // Write your code here.
  }

  // Pops an element from the back of the deque. Returns -1 if the deque is
  // empty, otherwise returns the popped element.
  int popRear() {
      if(isEmpty()) return -1;
      int val=arr[rear];
      if(front==rear){
          front=rear=-1;
          return val;
      }
      rear=(rear-1+size)%size;
      return val;
    // Write your code here.
  }

  // Returns the first element of the deque. If the deque is empty, it returns
  // -1.
  int getFront() {
    // Write your code here.
    return (isEmpty())? -1:arr[front];
  }

  // Returns the last element of the deque. If the deque is empty, it returns
  // -1.
  int getRear() {
      return (isEmpty())? -1:arr[rear];
    // Write your code here.
  }

  // Returns true if the deque is empty. Otherwise returns false.
  bool isEmpty() {
    // Write your code here.
    return (front==-1);
  }

  // Returns true if the deque is full. Otherwise returns false.
  bool isFull() {
        return  (front == (rear + 1) % size);
    // Write your code here.
  }
};
