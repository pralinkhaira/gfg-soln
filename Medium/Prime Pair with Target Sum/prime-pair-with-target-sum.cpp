//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int n){
      if(n==1 || n==0) return false;
      for(int i=2;i*i<=n;i++){
          if(n%i==0) return false;}
      return true;}
    vector<int> getPrimes(int n) {
        int a = -1,b=-1;
        for(int i=2;i<=n;i++){
            if(isPrime(i)&&isPrime(n-i)){
               return {i,n-i};}}
        return {a,b};
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends