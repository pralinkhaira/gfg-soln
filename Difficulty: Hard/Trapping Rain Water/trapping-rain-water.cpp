//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> l(n,0), r(n,0);
        
        int lmax = 0;
        for(int i = 0;i<n;i++){
            lmax = max(lmax,arr[i]);
            l[i] = lmax;
        }
        
        int rmax = 0;
        for(int j = n-1;j>=0;j--){
            rmax = max(rmax,arr[j]);
            r[j] = rmax;
        }
        
        int res = 0;
        for(int i = 0;i<n;i++){
            res += min(l[i],r[i])-arr[i];
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends