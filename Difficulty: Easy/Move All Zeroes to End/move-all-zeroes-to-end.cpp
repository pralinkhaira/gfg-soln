//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int r = 0 , q = 1;
        int n = arr.size();
        
        while(r < n && q < n){
           if(arr[r] != 0 && arr[q] != 0){
               r++ ;
               q++ ;
           }
           else if(arr[r] != 0 && arr[q] == 0){
               r = q;
               q++;
           }
           else if(arr[r] == 0 && arr[q] == 0){
               q++;
           }
           else{
               swap(arr[r] , arr[q]);
               r++;
               q++;
           }
        }
        
        return ;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends