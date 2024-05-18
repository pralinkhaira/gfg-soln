//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int low= 0, high= n-1;
        int ans= 0, d= INT_MAX;
        while(low<= high){
            int mid= low+ (high-low)/2;
           int dis= abs(k- arr[mid]);
            if(dis < d || (dis == d && arr[mid] > ans)){
                ans= arr[mid];
                d= dis;
            }
            if(arr[mid]== k)
            return ans;
            
            if(arr[mid]> k){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
          
        }
        return ans;
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
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends