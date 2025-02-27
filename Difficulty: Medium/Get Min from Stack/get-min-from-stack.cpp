//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<pair<int, int>> v;
    int min_ele=INT_MAX;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        min_ele=v.size()>0 ? min(x,v.back().second) : x;
        v.push_back({x,min_ele});
    }

    // Remove the top element from the Stack
    void pop() {
        if(v.size()>0)
            v.pop_back();
    }

    // Returns top element of the Stack
    int peek() {
        if(v.size()>0)
            return v.back().first;
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        if(v.size()>0)
            return v.back().second;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends