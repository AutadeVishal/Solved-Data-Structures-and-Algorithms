//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        vector<int>distance;
        vector<int>between;
        for(int i=0, j=1;i<stations.size()-1,j<stations.size()-1;i++,j++ ){
            distance.push_back((stations[j]-stations[i]));
        }
    }
};

//{ Driver Code Starts.
int main() {

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

    return 0;
}
// } Driver Code Ends