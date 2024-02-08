//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &arr, int n, int m){
        // code here       
        int l=1e8,h=-1e8;
        for(int i=0;i<n;i++){
            l=min(l,arr[i][0]);// min
            h=max(h,arr[i][m-1]);// max
        }
        int median_ind=(n*m)/2;// midle index

      while(l<=h){
          int mid=l+(h-l)/2;
          int cnt=0;
          for(int i=0;i<n;i++){// find no of element smaller then mid for every row
              int ub= upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();//upper bound
              cnt+=ub;
          }
          if(cnt>median_ind){// if greater then shrink h
              h=mid-1;
          }
          else{
              l=mid+1;
          }
      }
      return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends