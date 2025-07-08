#include <bits/stdc++.h> 
#include<stack>
void reverse(queue < int > & q) {
  /*  if que empty return
   int curr=
   pop curr;
   reverse(q);
   put curr in que*/
   stack<int>st;
   while(!q.empty()){
       st.push(q.front());
       q.pop();
   }
   while(!st.empty()){
       q.push(st.top());
       st.pop();

   }
}
