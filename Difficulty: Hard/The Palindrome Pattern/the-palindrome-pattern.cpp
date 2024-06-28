//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int s = 0, e = n-1;
            bool flag = true;
            
            while(s <= e) {
                if(arr[i][s] != arr[i][e]) {
                    flag = false;
                    break;
                }
                s++;
                e--;
            }
            
            if(flag) {
                return to_string(i) + " R";
            }
        }
        
        for(int i = 0; i < n; i++) {
            int s = 0, e = n-1;
            bool flag = true;
            
            while(s <= e) {
                if(arr[s][i] != arr[e][i]) {
                    flag = false;
                    break;
                }
                s++;
                e--;
            }
            
            if(flag) {
                return to_string(i) + " C";
            }
        }
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends