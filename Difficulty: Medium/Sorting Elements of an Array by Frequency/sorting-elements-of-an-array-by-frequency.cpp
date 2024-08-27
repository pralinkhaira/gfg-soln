//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool cmp(pair<int,int> p1,pair<int,int> p2){
        if(p1.second>p2.second){
            return true;
        }else if(p1.second==p2.second){
            return p1.first<p2.first;
        }else{
            return false;
        }
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back(it);
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(auto it:v){
            while(it.second){
                ans.push_back(it.first);
                it.second--;
            }
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends