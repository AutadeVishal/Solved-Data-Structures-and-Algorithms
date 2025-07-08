#include <bits/stdc++.h>
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    long long ma = LLONG_MIN;
    long long mi = LLONG_MAX; 
    long long sum = 0;        
    for (int i = 0; i < k; i++) {
        ma = max((long long)nums[i], ma); 
        mi = min((long long)nums[i], mi); 
    }
    sum = mi + ma;
    for (int j = k; j < n; j++) {
        if (nums[j - k] == mi) {
            mi = LLONG_MAX;
            for (int l = j - k + 1; l <= j; l++) {
                mi = min((long long)nums[l], mi);
            }
        }
        if (nums[j - k] == ma) {
            ma = LLONG_MIN;
            for (int l = j - k + 1; l <= j; l++) {
                ma = max((long long)nums[l], ma);  
            }
        }
        ma = max((long long)nums[j], ma);  
        mi = min((long long)nums[j], mi);  
        sum += mi + ma;
    }

    return sum;
}
