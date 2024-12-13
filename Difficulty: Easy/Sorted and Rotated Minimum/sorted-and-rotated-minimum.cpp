//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n=arr.size();
        int lo=0, hi=n-1;
        int ans=INT_MAX;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(arr[lo]<=arr[hi]){
                ans=min(ans, arr[lo]);
                break;
            }
            
            if(arr[lo]<=arr[mid]){
                ans=min(ans, arr[lo]);
                lo=mid+1;
            }else{
                ans=min(ans, arr[mid]);
                hi=mid-1;
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

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends