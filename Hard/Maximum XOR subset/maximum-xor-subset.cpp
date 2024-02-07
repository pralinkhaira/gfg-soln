//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxXor(int arr[], int n)
	{
		if(n == 1) return arr[0];
 
         int i = 0;
         for(int k=30; k>=0; k--) {
             int ma = INT_MIN, ma_ind = -1;
             
             for(int j=i; j<n; j++) {
                 if((arr[j]&(1<<k)) and arr[j] > ma) {
                     ma = arr[j];
                     ma_ind = j;
                 }
             }
             if(ma == INT_MIN) continue;
             //swap
             int temp = arr[i];
                arr[i] = arr[ma_ind];
                arr[ma_ind] = temp;
             
             for(int j=0; j<n; j++) {
                 if(j != i and (arr[j]&(1<<k))) {
                     arr[j] ^= arr[i];
                 }
             }
             
             i++;
         }
         
         int res = 0;
         for(int j=0; j<n; j++)
             res ^= arr[j];
         
         return res;

	}
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	   

	    Solution ob;
	    cout << ob.maxXor(a, n) << "\n";
   
    }
    return 0;
}

// } Driver Code Ends