//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int leftsum = arr[0];
        int rightsum = 0;
        int i=1,j=arr.size()-1;
        while(i <= j){
            if(leftsum < rightsum){
                leftsum += arr[i];
                i++;
            }else{
                rightsum += arr[j];
                j--;
            }
        }
        //cout<<leftsum<<"   "<<rightsum;
        return leftsum == rightsum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends