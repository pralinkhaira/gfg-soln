//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
    vector<int> nses;
    void count_NSE(vector<int>& arr,vector<int>& indcs,int l,int m,int r) {
        vector<int> in(r-l+1);
        int i=m,j=r,k=in.size()-1;
        while(i>=l&&j>m){
            if(arr[indcs[i]]>arr[indcs[j]]){ 
                in[k--]=indcs[i]; nses[indcs[i]]+=j-m; i--; 
            }
            else{ 
                in[k--]=indcs[j]; 
                /*if(arr[indcs[j]]<arr[indcs[i]]){ 
                    nges[indcs[j]]+=m+1-i;
                }*/
                j--;
            }
        }
        while(i>=l){
            in[k--]=indcs[i--];
        }
        while(j>m){
            in[k--]=indcs[j--];
        }
        for(int i=l;i<=r;i++) indcs[i]=in[i-l];
    }
    void count_NSEUtil(vector<int>& arr,vector<int>& indcs,int l,int r) {
        if(l==r) return;
        int m=(l+r)/2;
        count_NSEUtil(arr,indcs,l,m);
        count_NSEUtil(arr,indcs,m+1,r);
        count_NSE(arr,indcs,l,m,r);
    }
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        /*ordered_set o_set;     //Ordered_set soln.
    
        vector<int> ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            ans[i]=o_set.order_of_key(arr[i]);
            o_set.insert(arr[i]);
        }
        return ans;     //see BIT solution in Full Solution*/
        //Merge Sort Soln. O(NlogN)
        nses.assign(n,0);
        vector<int> indcs(n);
        for(int i=0;i<n;i++) indcs[i]=i;
        count_NSEUtil(arr,indcs,0,n-1);
        return nses;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends