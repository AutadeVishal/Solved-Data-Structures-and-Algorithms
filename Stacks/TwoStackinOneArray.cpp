#include <bits/stdc++.h>
class TwoStack {

public:
  int top1;
  int top2;
  int *arr;
  int size;
  // Initialize TwoStack.
  TwoStack(int s) {
    // Write your code here.
    size=s;
    arr=new int[size];
    top1 = -1;
    top2 = size;
  }

  // Push in stack 1.
  void push1(int num) {
    // Write your code here.
    if (top1 + 1 < top2) {
      arr[top1 + 1] = num;
      top1++;
    }
  }

  // Push in stack 2.
  void push2(int num) {
    // Write your code here.
    if (top1 + 1 < top2) {
      arr[top2 - 1] = num;
      top2--;
    }
  }

  // Pop from stack 1 and return popped element.
  int pop1() {
    // Write your code here.
    if (top1 > -1) {
        int val=arr[top1];
      top1--;
      return val;
    }
    else return -1;
  }

  // Pop from stack 2 and return popped element.
  int pop2() {
    // Write your code here.
    if (top2 < size) {
      
    int val=arr[top2];
    top2++;
    return val;
    } else
      return -1;
  }
};
