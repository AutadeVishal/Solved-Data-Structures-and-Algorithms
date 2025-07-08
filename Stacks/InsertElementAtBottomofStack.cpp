#include <bits/stdc++.h>
stack<int> pushAtBottom(stack<int> &myStack, int x) {
  if (!myStack.empty()) {
    int value = myStack.top();
    myStack.pop();
  pushAtBottom(myStack, x);
  myStack.push(value);
  }
  else{
      myStack.push(x);
  }
  return myStack;
}
