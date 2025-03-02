//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        
        
        deque<int> qu;
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++) {
            while(!qu.empty() && qu.back() < arr[i]) qu.pop_back();
            qu.push_back(arr[i]);
            
            if(i >= (k - 1)) {
                ans.push_back(qu.front());
                if(arr[i - k + 1] == qu.front()) qu.pop_front();
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // code here
        // vector<int>maxValue;
        // int max = 0;
        // int value = 0;
        
        // for(int i=0;i<arr.size();i++)
        // {
        //     int n = k+i;
        //     if(n>arr.size()) return maxValue;
        //     for(int j=i;j<n;j++)
        //     {
        //         value = arr[j];
                
        //         if(max < value)
        //         {
        //             max = value;
        //         }
        //     }
            
        //     maxValue.push_back(max);
            
        //     max = 0;
        //     value = 0;
        // }
        
        // return maxValue;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends