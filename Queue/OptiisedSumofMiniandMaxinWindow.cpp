#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
deque<long long>maxi,mini;
long long sum=0;
for(int i=0;i<k;i++){
    while(!maxi.empty() && nums[maxi.back()]<nums[i]){
        maxi.pop_back();
    }
      while(!mini.empty() && nums[mini.back()]>nums[i]){
        mini.pop_back();
    }
    maxi.push_back(i);
    mini.push_back(i);
}
sum+=(nums[mini.front()]+nums[maxi.front()]);
for(int i=k;i<n;i++){
       while(!maxi.empty() && nums[maxi.back()]<nums[i]){
        maxi.pop_back();
    }
      while(!mini.empty() && nums[mini.back()]>nums[i]){
        mini.pop_back();
    }
    while(!maxi.empty() && maxi.front()<=i-k){
        maxi.pop_front();
    }
    while(!mini.empty() && mini.front()<=i-k){
        mini.pop_front();
    }
    mini.push_back(i);
    maxi.push_back(i);
    sum+=(nums[maxi.front()]+nums[mini.front()]);
}
return sum;
}
