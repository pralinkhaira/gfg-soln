//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        unordered_map<int,int>ump;
        for(int i=0;i<arr.size();i++)
        {
            ump.insert({arr[i],i});
        }
        
        unordered_map<int,int>::iterator it=ump.begin();
        while(it!=ump.end())
        {
            if(it->first==key)
            return it->second;
            it++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends