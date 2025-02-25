//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
         stack<pair<int,int>>s1,s2;
        vector<int>r(n);
        s1.push(make_pair(-1,n));
        for(int i=n-1;i>=0;i--){
            while(arr[i]<=s1.top().first){
                s1.pop();
            }
            r[i]=s1.top().second;
            s1.push(make_pair(arr[i],i));
        }
        vector<int>l(n);
        s2.push(make_pair(-1,-1));
        for(int i=0;i<n;i++){
            while(arr[i]<=s2.top().first){
                s2.pop();
            }
            l[i]=s2.top().second;
            s2.push(make_pair(arr[i],i));
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,arr[i]*(r[i]-l[i]-1));
            
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends