//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<vector>
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        vector<long double> v;
        vector<int> n(stations.size() - 1, 0);
        for (int j = 1; j < stations.size(); ++j) {
            v.push_back(stations[j] - stations[j - 1]);
        }
        
        
        auto findMaxDistIndex = [&]() {
            int maxIndex = 0;
            for (int i = 1; i < v.size(); ++i) {
                if (v[i] > v[maxIndex]) {
                    maxIndex = i;
                }
            }
            return maxIndex;
        };
        

        while (k--) {
            int maxd = findMaxDistIndex();
            
            
            n[maxd]++;
            v[maxd] = v[maxd] / (n[maxd] + 1);
        }
        
        long  double maxdist = *max_element(v.begin(), v.end());
        
        return maxdist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends