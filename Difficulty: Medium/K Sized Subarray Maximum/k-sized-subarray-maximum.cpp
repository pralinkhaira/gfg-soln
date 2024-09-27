//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   int fun( queue<int>&q){
        int m=0;
        int s=q.size();
        for(int i=0;i<s;i++){
            int a=q.front();
            q.pop();
            q.push(a);
            m=max(m,a);
        }
        
        return m;
    }
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
          vector<int> vec;
    if (arr.size() < k || k <= 0) return vec;
    queue<int> q;
    int m = INT_MIN;
    for (int i = 0; i < k; i++) {
        m = max(m, arr[i]);
        q.push(arr[i]);
    }
    vec.push_back(m);
     
     for(int i=k;i<arr.size();i++){
         int a=q.front();
         q.pop();
         q.push(arr[i]);
         if(a==m){
            if(a<arr[i]){
                m=arr[i];
            }
            else{
                m=fun(q); 
            }
         }
         else{
             if(m<arr[i]){
                 m=arr[i];
             }
         }
         vec.push_back(m);
     }   
  return vec;   
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends