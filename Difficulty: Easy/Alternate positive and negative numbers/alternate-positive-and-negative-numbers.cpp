//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;
        for(int i: arr){
            if (i < 0) neg.push_back(i);
            else pos.push_back(i);
        }
        vector<int> res;
        
        int i=0,j=0;
        while(i < pos.size() && j < neg.size()){
            res.push_back(pos[i]);
            res.push_back(neg[j]);
            i++;j++;
        }
        while(i < pos.size()){
            res.push_back(pos[i]);
            i++;
        }
        while(j < neg.size()){
            res.push_back(neg[j]);
            j++;
        }
        arr = res;
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends