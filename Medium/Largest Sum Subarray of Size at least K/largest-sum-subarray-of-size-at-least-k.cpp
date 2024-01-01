//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
   long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
{
    long long int i=0;
    long long int j=0;
    long long int sumj=0;
    long long int sumi=0;
    long long int maxi=INT_MIN;
    
    while(j<n)
    {
        sumj+=arr[j];
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            maxi=max(maxi,sumj);
            j++;
        }
        else if((j-i+1)>k){
            maxi=max(maxi,sumj);
            sumi+=arr[i];
            i++;
            if(sumi<0) //jab negative hojaega sum i wala toh yeh operation perform krdo
            {
                sumj-=sumi;
                maxi=max(sumj,maxi);
                sumi=0;
            }
            j++;
        }
        
    }
    return maxi;
}
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends