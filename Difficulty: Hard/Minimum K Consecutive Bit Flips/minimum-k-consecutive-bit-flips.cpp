//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n =arr.size();
        int ans=0;
        vector<int> hash(n,0);
        int curr_flips=0;
        for(int i=0;i<n;i++){
            if((arr[i]==0 && curr_flips%2==0) || (arr[i]==1 && curr_flips%2!=0)){
                if(k>n-i){
                    return -1;
                }
                curr_flips+=1;
                hash[i]=1;
                ans++;
            }
            if(i-k+1>=0){
                curr_flips-=hash[i-k+1];
            }
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        cout << ob.kBitFlips(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends