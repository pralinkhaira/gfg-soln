//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
      long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        // Create temporary arrays
        vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

        // Indices for iteration
        int i = 0, j = 0, k = left;
        long long count = 0;

        // Merge the two subarrays and count inversions
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                count += leftArr.size() - i; // Count inversions
            }
        }

        // Copy remaining elements of leftArr
        while (i < leftArr.size()) {
            arr[k++] = leftArr[i++];
        }

        // Copy remaining elements of rightArr
        while (j < rightArr.size()) {
            arr[k++] = rightArr[j++];
        }

        return count;
    }

    long long mergeSortAndCount(vector<int>& arr, int left, int right) {
        long long count = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in left half
            count += mergeSortAndCount(arr, left, mid);

            // Count inversions in right half
            count += mergeSortAndCount(arr, mid + 1, right);

            // Count split inversions
            count += mergeAndCount(arr, left, mid, right);
        }

        return count;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends