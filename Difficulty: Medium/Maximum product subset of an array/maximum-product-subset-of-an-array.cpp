//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n=arr.size();
        if(n==1) return arr[0];
        int k=0,r=0;
        const long long int mod = 1000000007;
        int maxi=INT_MIN;
        long long int sum=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0){
                sum=(sum*arr[i])%mod;
                r=1;
            }
            else{ k=1;}
            if(arr[i]<0 and arr[i]>maxi)
            maxi=arr[i];
        }
        if(r!=1) return 0;
        if(arr.size()==2 and k==1 and sum<0) return 0;
        if(sum<0) sum/=maxi;
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends