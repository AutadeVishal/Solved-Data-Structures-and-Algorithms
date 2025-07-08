//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        
        int s = 1;
        int e = N - 1;
        int result = 0;
       
        while (s <= e) {
            int mid = s + (e - s) / 2;
           long long  squared1=static_cast<long long> (mid)*static_cast<long long>(mid);
            if (squared1 < N) {
                result = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends