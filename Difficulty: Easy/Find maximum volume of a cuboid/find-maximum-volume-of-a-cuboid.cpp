//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double P, double A) 
    {
        double l = (P - sqrt(P * P - 24 * A)) / 12;
        double height = (P / 4) - (2 * l);
        double ans = l * l * height;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends