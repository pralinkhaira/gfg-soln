//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long mod = 1e9 + 7;
        // same[i] = number of possibilities with 2 consecutive same
        // diff[i] = number of possibilities that 2 consecutive are not same
        // we want the sum of 2 non-consecutive and 2 consecutive 
        long long diff = k;
        long long same = 0;
        long long total = k;
        
        if(n == 1)
            return total;
        else {
            for(int i=2; i<=n; i++) {
                same = (diff)%mod;
                diff = (total * (k-1)) % mod;
                total = (same + diff) % mod;
            }
        }
        
        return (total)%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends