//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int binaryrSearch(int *arr, int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1; // Element not found
    }

    int findSwapValues(int a[], int n, int b[], int m) {
        sort(a, a + n);
        sort(b, b + m);

        int sumA = 0, sumB = 0;
        for (int i = 0; i < n; i++) {
            sumA += a[i];
        }
        for (int i = 0; i < m; i++) {
            sumB += b[i];
        }
        if (sumA == sumB) return 1;
        int diff = sumA - sumB;

        // If the difference is odd, no swap can equalize the sums
        if (diff % 2 != 0) return -1;
        // Target value to find (half of the difference)
        int target = diff / 2;
        // Look for pairs (a[i], b[j]) such that a[i] - b[j] = target
        for (int i = 0; i < n; i++) {
            int find = a[i] - target;
            if (binaryrSearch(b, m, find) != -1) {
                return 1; // Swap found
            }
        }
        return -1; 
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends