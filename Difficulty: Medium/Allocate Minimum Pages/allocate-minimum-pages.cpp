//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isFeasible(const vector<int>& arr, int n, int k, int maxPages) {
    int studentsRequired = 1;
    int currentPages = 0;

    for (int pages : arr) {
        if (pages > maxPages) {
            return false; // A single book has more pages than maxPages.
        }

        if (currentPages + pages > maxPages) {
            // Allocate to a new student
            studentsRequired++;
            currentPages = pages;

            if (studentsRequired > k) {
                return false; // Too many students required
            }
        } else {
            currentPages += pages;
        }
    }
    return true;
}
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if (k > n) {
        return -1; // Not enough books for every student to get at least one
    }

    int low = *max_element(arr.begin(), arr.end()); // Minimum possible max pages
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible max pages
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow

        if (isFeasible(arr, n, k, mid)) {
            result = mid;   // Update result with the feasible mid
            high = mid - 1; // Try for a smaller maximum
        } else {
            low = mid + 1;  // Try for a larger maximum
        }
    }
    return result;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends