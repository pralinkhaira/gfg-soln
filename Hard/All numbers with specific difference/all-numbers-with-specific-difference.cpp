//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long getCount( long long n, long long d ) {
    long long l{ 1 }, r{ n };
    do { long long mid{ l + r >> 1 }, temp{ mid }, sum{};
        do sum += temp % 10; while ( temp /= 10 );
        mid - sum < d ? l = ++mid : r = --mid;
    } while ( l <= r );
    return n - r;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N,D;

        cin>>N>>D;

        Solution ob;
        cout << ob.getCount(N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends