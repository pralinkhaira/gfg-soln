//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        map<int,int> mp;

        mp[0]=0;

        int curSum=0;

        for(int i=0; i<arr.size(); i++){

            if(curSum==target) return {1,i+1};

            curSum=arr[i]+curSum;

            if(mp.find(curSum-target)!=mp.end()){

                return {mp[curSum-target]+1,i+1};

            }

            if(mp.find(curSum)==mp.end()){

                mp[curSum]=i+1;

            }

        }

        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends