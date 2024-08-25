//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  #define ll long long int
    long long countPairs(vector<int> &a, vector<int> &b) {
        vector<double> c;
        vector<double> d;
        for(int i=0;i<a.size();i++){
           
            ll x=a[i];
             if(x==1) continue;
            double val=log(x)/(x*1.0);
          // cout<<val<<" ";
            
            c.push_back(val);
             }
           //  cout<<endl;
             for(int i=0;i<b.size();i++){
                 ll x=b[i];
                // if(x==1) continue;
                 double val=log(x)/(x*1.0);
              //   cout<<val<<" ";
                 d.push_back(val);
             }
             sort(d.begin(),d.end());
             ll ans=0;
             for(int i=0;i<c.size();i++){
                 double val=c[i];
                 ll bound=lower_bound(d.begin(),d.end(),val)-d.begin();
                 ans+=bound;
             }
             return ans;
             }
    
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends