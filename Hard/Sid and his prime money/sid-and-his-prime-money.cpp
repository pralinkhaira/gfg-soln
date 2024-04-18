//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


const int maxN = 100005;
static int dp[maxN]; // SPF array

const auto primes = [] {
    for (int i = 0; i < maxN; i++) {
        dp[i] = i;
    }
    dp[0]=dp[1] = -1;
    for (int i = 2; i * i < maxN; i++) {
        if (dp[i] == i)
            for (int j = i * i; j < maxN; j += i) {
                dp[j] = i;
            }
    }
    return true;
}();
class Solution{
    public:
    
    pair<int,int> primeMoney(int a[], int n)
    {
        int cnt = 0;
        int maxCnt = 0;
        int sum = 0, maxSum = 0;
        if(dp[a[1]] == a[1]) sum = maxSum = a[1];
        cnt = maxCnt = 1;
        for(int i=2; i<n+1; i++) {
            if(a[i] > a[i-1]) {
                if(dp[a[i]] == a[i]) {
                    sum += a[i];
                }
                cnt++;
                if(cnt == maxCnt) maxSum = max(maxSum, sum);
                if(cnt > maxCnt) {// simply override
                    maxSum =sum;
                    maxCnt = cnt;
                }
            }
            else {
                cnt = 1;
                sum=0;
                if(dp[a[i]] == a[i]) 
                    sum = a[i];
                if(cnt == maxCnt) maxSum = max(maxSum, sum);
                if(cnt > maxCnt) {
                    maxSum = sum;
                    maxCnt = cnt;
                }
            }
        }
        return make_pair(maxCnt, maxSum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, i;
        cin >> n;
        int a[n + 1];
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        Solution ob;
        pair<int,int> pp = ob.primeMoney(a, n);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

// } Driver Code Ends