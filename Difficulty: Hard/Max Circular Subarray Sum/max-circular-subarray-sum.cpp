//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kadane(vector<int> &arr){
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<arr.size();i++){
            sum +=arr[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int normalsum= kadane(arr);
        if(normalsum<0) return normalsum;
        int currsum=0;
        for(int i=0;i<arr.size();i++){
            currsum +=arr[i];
            arr[i] *= -1;
        }
        int circularsum= currsum+kadane(arr);
        return max(normalsum, circularsum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends