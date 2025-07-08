#include <bits/stdc++.h> 
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int>st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++){
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<(q.size()-k);i++){
        int a=q.front();
        q.push(a);
        q.pop();
    }
    return q;
}
