//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
bool check(vector<string>&arr,int mid){
    string s;
    for(int i=0;i<=mid;i++){
    s+=arr[0][i];
    }
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<=mid;j++){
            if(s[j]==arr[i][j]) continue;
            else return false;
        }
    }
    return true;
}
    string longestCommonPrefix(vector<string> &arr) {
        // your code here
        int n=arr.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(int)arr[i].length());
        }
        int low=0,high=maxi-1,ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            bool flag=check(arr,mid);
            if(flag){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
            
        }
        if(ans==-1) return "-1";
        string temp;
        for(int i=0;i<=ans;i++){
            temp+=arr[0][i];
        }
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends