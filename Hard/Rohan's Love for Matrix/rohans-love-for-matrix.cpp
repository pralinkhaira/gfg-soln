//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long firstElement(int n) {
        // code here
        int firstN,secondN,i,value;;
        firstN=1;
        secondN=1;
        i=3;
        if(n==1 || n==2){
            return 1;
        }
        
        while(i<=n){
            value=(firstN+secondN)%1000000007;
            firstN=secondN;
            secondN=value;
            i++;
        }
        return value%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends