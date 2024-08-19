//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        int count=0;
        int distance=0;
        while(distance<d)
        {
            distance+=count;
            count++;
        }
        if(distance==d)
        {
            return count-1;
        }
        else
        {
            if((distance-d)%2==0)
            {
                return count-1;
            }
            else
            {
                if(count%2==0)
                return count+1;
                
                else
                return count;
            }
            
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends