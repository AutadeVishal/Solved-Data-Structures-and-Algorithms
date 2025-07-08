#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    st.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        start:
        if(st.top()<arr[i]){
            int k=st.top();
            st.push(arr[i]);
            arr[i]=k;
        }
        else{
            st.pop();
            goto start;
        }
    }
    return arr;
}
