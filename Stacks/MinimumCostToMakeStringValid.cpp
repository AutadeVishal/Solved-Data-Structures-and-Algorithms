#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  stack<char>st;
  int o=0,c=0;
  for(char i:str){
    if(i=='{'){
      st.push(i);
      o++;
    } else {
      if (!st.empty() && st.top() == '{'){
        st.pop();
        o--;
      }
      else{
        st.push(i);
        c++;
      }
    }
  }
  if ((o + c) % 2 != 1) {
    return (o + 1) / 2 + (c + 1) / 2;
  }
  else return -1;
}
