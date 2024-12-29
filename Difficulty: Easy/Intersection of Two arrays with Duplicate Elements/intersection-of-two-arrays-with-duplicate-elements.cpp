//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        set<int> st;
        
        // storing array b in st to remove all duplicates
        for(int i = 0; i < b.size(); i++){
            st.insert(b[i]);
        }
        
        set<int> sta;
        
        // storing array a in sta to remove all duplicates
        for(int i = 0; i < a.size(); i++){
            sta.insert(a[i]);
        }
        
        // res array
        vector<int> res;
        
        for(int val : sta){
            // if val is present in st then push it into result array
            if(st.find(val) != st.end()){
                res.push_back(val);
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends