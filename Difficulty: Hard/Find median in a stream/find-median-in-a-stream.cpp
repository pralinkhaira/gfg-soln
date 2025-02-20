//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
    priority_queue<int> maxHeap; // Max heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the larger half
    vector<double> medians;

    for (int num : arr) {
        // Step 1: Insert into maxHeap
        maxHeap.push(num);

        // Step 2: Move maxHeap's top to minHeap to maintain order
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Balance heaps (maxHeap should be >= minHeap size)
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Step 4: Compute median
        if (maxHeap.size() > minHeap.size()) {
            medians.push_back(maxHeap.top());
        } else {
            medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
        }
    }

    return medians;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends