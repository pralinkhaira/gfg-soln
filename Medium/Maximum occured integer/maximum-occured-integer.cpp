//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        vector<int> pref(maxx+2,0);
        for(int i=0;i<n;i++){
            int start = l[i];
            int end = r[i];
            pref[start] += 1;
            pref[end+1] -= 1;
        }
        int prefix = 0;
        for(int i=0;i<(maxx+2);i++){
            prefix += pref[i];
            pref[i] = prefix;
            // cout<<i<<" "<<pref[i]<<endl;
        }
        int count = 0, ans = 0;
        for(int i=0;i<(maxx+2);i++){
            if(pref[i]>count){
                ans = i;
                count = pref[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends