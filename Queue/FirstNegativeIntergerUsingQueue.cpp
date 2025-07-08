#include <bits/stdc++.h> 
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{
deque<int>dq;
vector<int>ans;
    //Write your code here
for(int i=0;i<k;i++){
    if(arr[i]<0){
        dq.push_back(i);
    }
}
ans.push_back((dq.empty())? 0:arr[dq.front()]);
for(int i=k;i<n;i++){
    if(arr[i]<0){
        dq.push_back(i);
    }
    while(!dq.empty() && i-dq.front()>=k){
        dq.pop_front();
    }
    ans.push_back((dq.empty())? 0:arr[dq.front()]);
}
return ans;



}
