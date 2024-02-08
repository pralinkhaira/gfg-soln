//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool possible(vector<int> &stalls , int minDist ,int reqCow ){
        int cow =1;
        int last = stalls[0];
        int n= stalls.size();
       
        for(int i=1 ;i<n;i++){
          int diff = stalls[i] - last;
          if(diff >= minDist){
              cow++;
              last= stalls[i];
          }
          if (cow >= reqCow){
              return true;
          }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        // Write your code here
      
        int s =1;
        int e = stalls[n-1] - stalls[0];
        int mid = s + (e-s)/2;
        while(s<=e){
            // cout<<mid<<" ";
            bool check =possible(stalls,mid,k);
            // cout<<endl<<check<<endl;
            if(check){
                s=mid+1;
            }
            else{
                e= mid-1;
            }
            mid= s+(e-s)/2;
        }
        return e;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends