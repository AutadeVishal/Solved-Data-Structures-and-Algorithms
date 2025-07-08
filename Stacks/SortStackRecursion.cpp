#include <bits/stdc++.h> 
void sortpush(stack<int>&stack,int value){
	if(!stack.empty()){
		if(stack.top()>value){
			int curr=stack.top();
			stack.pop();
			sortpush(stack,value);
			stack.push(curr);
			return;
		}
		else{
			stack.push(value);
			return ;
		}
	}
	else{
		stack.push(value);
	}
}
void sortStack(stack<int> &stack)
{
	if(!stack.empty()){
		int curr=stack.top();
		stack.pop();
		sortStack(stack);
		sortpush(stack,curr);
	}

}
