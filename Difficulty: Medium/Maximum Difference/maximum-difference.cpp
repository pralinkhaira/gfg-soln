//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &a) {
        // Your code here
        int n=a.size();
    stack<int>l,r;
     vector<int>left(n,0);
     vector<int>right(n,0);
     l.push(a[0]);
    //  left.push_back(0);
     for(int i=1;i<n;i++)
     {
         
          while(!l.empty() && l.top()>=a[i])
         l.pop();
         if(!l.empty())
         left[i]=(l.top());
         else left[i]=0;
         l.push(a[i]);
     }
     r.push(a[n-1]);
     right[n-1]=0;
     for(int i=n-2;i>=0;i--)
     {
         while(!r.empty() && r.top()>=a[i])
         r.pop();
         if(!r.empty())
        right[i]=r.top();
        else right[i]=0;
        r.push(a[i]);
        
     }
     int mx=INT_MIN;
     for(int i=0;i<n;i++)
     {
        //  cout<<left[i]<<" "<<right[i]<<endl;
         mx=max(mx,abs(left[i]-right[i]));
     }
     return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends