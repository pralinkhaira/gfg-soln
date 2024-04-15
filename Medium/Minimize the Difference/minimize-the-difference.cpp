//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> maxfront(n,-1);
        vector<int> maxback(n,-1);
        vector<int> minfront(n,INT_MAX);
        vector<int> minback(n,INT_MAX);
        for(int i=1; i<n;i++){
            maxfront[i] = max(maxfront[i-1],arr[i-1]);
            minfront[i] = min(minfront[i-1],arr[i-1]);
        }
        for(int i=n-2; i>=0;i--){
            maxback[i] = max(maxback[i+1],arr[i+1]);
            minback[i] = min(minback[i+1],arr[i+1]);
        }
        int ans = INT_MAX;
        for(int i=0; i<n-k+1;i++){
            int maxi = max(maxfront[i],maxback[i+k-1]);
            int mini = min(minfront[i],minback[i+k-1]);
            ans = min(ans,maxi-mini);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends