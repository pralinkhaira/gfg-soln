//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        //CodeGenius
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<arr.size();i++){
            int target=arr[i];
            int start=i+1;
            int end=arr.size()-1;
            while(start<end){
                if(arr[start]+arr[end]==target) return true;
                else if(arr[start]+arr[end]>target) start++;
                else end--;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends