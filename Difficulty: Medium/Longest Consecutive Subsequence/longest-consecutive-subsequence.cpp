//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int maxi=*max_element(arr.begin(),arr.end());
        vector<int>vec(maxi+1,0);
        for(int i=0;i<arr.size();i++)
        {
            vec[arr[i]]++;
        }
        int ans=-1e9;
        int count=0;
        for(int i=0;i<=maxi;i++)
        {
            if(vec[i]>0)
            {
                count++;
            }
            else
            {
                ans=max(ans,count);
                count=0;
            }
        }
        return max(ans,count);// Your code here
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends