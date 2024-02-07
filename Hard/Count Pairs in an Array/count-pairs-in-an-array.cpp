//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int count = 0;
    void merge(int arr[], int l, int m, int r)
    {
         vector<int> temp(r-l+1);
         int i =l , j= m+1 , k = 0;
         while(i <= m && j<= r){
             if(arr[i] <= arr[j]) temp[k++] = arr[i++];
             else count += m-i+1, temp[k++] = arr[j++];
         }
         while(i <= m) temp[k++] = arr[i++];
         while(j <= r) temp[k++] = arr[j++];
         for(int i =l , j =0 ;j < r-l+1;  i++) arr[i] = temp[j++];
    }
    
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r) return;
        int mid = (l+r)/2;
        mergeSort(arr , l , mid);
        mergeSort(arr , mid+1 , r);
        merge(arr , l , mid , r);
    }
    
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        for(int i = 0 ; i< n; i++)   arr[i] *= i;
        mergeSort(arr , 0 , n-1);
        return count;
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