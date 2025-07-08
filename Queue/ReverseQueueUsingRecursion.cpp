#include <bits/stdc++.h> 
#include<stack>
void reverse(queue < int > & q) {
  /*  if que empty return
   int curr=
   pop curr;
   reverse(q);
   put curr in que*/
   if(q.empty()) return;
   int curr=q.front();
   q.pop();
   reverse(q);
    q.push(curr);
}
