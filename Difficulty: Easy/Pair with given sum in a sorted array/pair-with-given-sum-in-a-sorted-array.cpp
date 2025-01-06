//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int ans=0;
        int start=0, end=arr.size()-1;
        while (start<end) {
            int sum = arr[start] + arr[end];
            if (sum==target) {
                int cnt1=1, cnt2=1;
                while (start<end && arr[start] == arr[start+1]) {
                    start++;
                    cnt1++;
                }
                while (start<end && arr[end] == arr[end-1]) {
                    end--;
                    cnt2++;
                }
                if (arr[start] == arr[end]) ans+=cnt1*(cnt1-1)/2;
                else ans+=cnt1*cnt2;
                start++;
                end--;
            }
            else if (sum<target) start++;
            else end--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends