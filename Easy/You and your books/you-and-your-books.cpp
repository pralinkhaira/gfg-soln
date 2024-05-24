//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        int64_t maxi = 0;
        int64_t j = 0;
        int64_t sum = 0;
        while(j<n)
        {
            if(arr[j]>k)
            {
                maxi = max(maxi,sum);
                sum = 0;
            }
            else sum += arr[j];
            j++;
        }
        maxi = max(sum,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends