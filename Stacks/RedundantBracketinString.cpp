#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{stack<char>st;
    for(char i:s){
        if(i=='(' || i=='+' || i=='-' || i=='*' || i=='/' ){
            st.push(i);
        }
        else{
            bool k=false;
            if(i==')'){
                char c=st.top();
                while(st.top()!='('){
                    if(c=='+' || c=='-' || c=='/' || c=='*'){
                        k=true;
                    }
                    st.pop();
                }
                if(k==true){
                    st.pop();
                } else {
                    return true;
                }
            }
        }
    }
    return false;
}
