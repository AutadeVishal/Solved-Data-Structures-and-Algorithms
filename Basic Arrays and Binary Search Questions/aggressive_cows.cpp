#include <algorithm>
#include <vector>
using namespace std;

bool ispossible(int n, int k, vector<int>& stalls, int mid) {
    int c = 1; 
    int s = 0; 
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - stalls[s] >= mid) {
            c++;  
            s = i; 
            if (c == k) {
                return true; 
            }
        }
    }
    return false; 
}

class Solution {
public:
    int solve(int n, int k, vector<int>& stalls) {
        sort(stalls.begin(), stalls.end());
        
        int low = 1; 
        int high = stalls[n-1] - stalls[0];  
        int mid, ans = 0;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            if (ispossible(n, k, stalls, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};
