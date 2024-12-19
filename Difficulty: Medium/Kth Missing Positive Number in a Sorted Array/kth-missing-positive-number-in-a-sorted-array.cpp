//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int binarySearch(vector<int>&arr,int k){
      int low = 0;
      int high = arr.size()-1;
      int ans = -1;
      while(low<=high){
        int mid = low+(high-low)/2;
        if((arr[mid]-(mid+1))<k){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
      }
      return ans;
  }
  int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int start = binarySearch(arr,k);
        if(start==-1){
            return k;
        }
        // k= k-(arr[start]-(start+1));
        // return arr[start]+k;
        return k+start+1;
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
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends