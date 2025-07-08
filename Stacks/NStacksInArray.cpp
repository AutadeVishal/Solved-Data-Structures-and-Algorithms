#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int *top;
    int *freeposition=new int(0);
    int *next;
    int n,s;
    NStack(int N, int S)
    {
        n=N,s=S;
        arr=new int[s];
        top=new int[n];
        next =new int[S];
        for(int i=0;i<s-1;i++){
            next[i]=i+1;

        }
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        next[s-1]=-1;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(*freeposition==-1)return false;
        m--;
        int index=*freeposition;
         arr[index]=x;
         *freeposition=next[index];
          next[index]=top[m];
        top[m]=index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {m--;
    if(top[m]==-1) return -1;
        int index=top[m];
        top[m]=next[index];
        next[index]=*freeposition;
        *freeposition=index;
        return arr[index];
    }
};
