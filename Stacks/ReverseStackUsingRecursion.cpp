void pushtobottom(stack<int>&stack,int value){
    if(!stack.empty()){
        int curr=stack.top();
        stack.pop();
        pushtobottom(stack,value);
        stack.push(curr);
    }
    else{
        stack.push(value);
    }
}
void reverseStack(stack<int> &stack) {
    if(!stack.empty()){
        int curr=stack.top();
        stack.pop();
        reverseStack(stack);
        pushtobottom(stack,curr);
    }
}
