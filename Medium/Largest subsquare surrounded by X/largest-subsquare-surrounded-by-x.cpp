//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
      int largestSubsquare(int n, vector<vector<char>> A) {

        // code here

        pair<int,int>dp[1001][1001];

        for(int i=0;i<n;i++)

        {

            int cntx=0;

            for(int j=0;j<n;j++)

            {

                if(A[i][j]=='X')

                cntx++;

                else

                cntx=0;

                dp[i][j].first=cntx;

            }

        }

        for(int i=0;i<n;i++)

        {

            int cntx=0;

            for(int j=0;j<n;j++)

            {

                if(A[j][i]=='X')

                cntx++;

                else

                cntx=0;

                dp[j][i].second=cntx;

            }

        }

        int maxi=0;

        for(int i=n-1;i>=0;i--)

        {

            for(int j=n-1;j>=0;j--)

            {

                int sm=min(dp[i][j].first,dp[i][j].second);

                while(sm>0)

                {

                if(dp[i][j-sm+1].second>=sm and dp[i-sm+1][j].first>=sm)

                {

                    break;

                }

                else

                sm--;

                }

                maxi=max(maxi,sm);

            }

        }

        return maxi;  // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends