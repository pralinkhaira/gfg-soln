//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=a[i];
        }
        
        long long initial=0, max=0;
        for(long long i=0;i<n;i++){
            initial+=i*a[i];
        }
        max=initial;
        
        for(long long i=1;i<n;i++){
            long long next=initial - (sum-a[i-1]) + 1LL*(n-1)*a[i-1];
            initial=next;
            if(max<initial){
                max=initial;
            }
        }
        return max;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends