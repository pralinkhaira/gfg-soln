//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
         vector<int> b,s;
        for(int i=0;i<n;i++){
            b.push_back((i * arr[i]));
            s.push_back(b[i]);
        }
        sort(s.begin(), s.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            int i1 = lower_bound(s.begin(), s.end(), b[i]) - s.begin();
            ans += i1;
            s.erase((s.begin() + i1));
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends