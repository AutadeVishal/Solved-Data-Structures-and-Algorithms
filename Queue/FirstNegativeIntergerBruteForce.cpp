#include <bits/stdc++.h> 
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{
    vector<int>ans;
    for(int i=0;i<n-k+1;i++){
        int nega=0;
        for(int j=i;j<k+i;j++){
            if(arr[j]<0){
                nega=arr[j];
                ans.push_back(arr[j]);
                break;
            }
            
        }
        if(nega==0) ans.push_back(0);
    }
    return ans;
    //Write your code here

}

