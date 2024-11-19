//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        /*
        // Easiest way-1 -> Better Approach
        next_permutation(arr.begin(),arr.end());
        */
        
        //Optimal Approach
        int index=-1;
        int n =arr.size();
        
        for(int i=n-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                index=i;
                break;
            }
        }
        
        if(index==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        
        for(int i=n-1;i>=index;i--){
            if(arr[i] > arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
        
        reverse(arr.begin()+index+1,arr.end());
        return;
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
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends