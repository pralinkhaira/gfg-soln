//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int x) 
    {
            long long int ans=0;
            int s=0;
            int e=x;
            while(s<=e)
            
            {
              long long int mid=(s+e)>>1;
                if(mid*mid<=x)
                {
                    ans=mid;
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
            return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends