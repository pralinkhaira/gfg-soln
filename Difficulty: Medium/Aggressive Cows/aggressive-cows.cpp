//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int checker(vector<int>&arr, int k, int d){
        int count = 1;
        int prev = arr[0];
        for(int i=1;i<arr.size();i++)
            if(arr[i] - prev >= d){
                prev = arr[i];
                count++;
            }
        return count >= k;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int l = 1, h = stalls[n-1]-stalls[0];
        int res = 0;
        while(l<=h){
            int m = l + (h-l)/2;
            if(checker(stalls, k, m)){
                res = m;
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends