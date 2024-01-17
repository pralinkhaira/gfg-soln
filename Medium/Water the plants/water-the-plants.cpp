//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<long long int> jump(n, -1);
        for(int i = 0; i < n; i++){
            long long int x = max(0, i-gallery[i]), y = min(n-1, i+gallery[i]);
            jump[x] = max(jump[x], y);
        }

        int res = 0;
        long long int max_reachable = -1;
        for(int i = 0; i < n; res += 1){
            long long int dist = max(jump[i], max_reachable);
            if(dist < 0 or res > n) return -1;
            if(dist >= n) return res;
            for(; i <= dist and i < n; i++){
                if(jump[i] > 0) max_reachable = max(max_reachable, jump[i]);
            }
            dist = max_reachable;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends