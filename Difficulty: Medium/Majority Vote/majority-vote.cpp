//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> findMajority(vector<int>& nums) {
        // Edge case for an empty array
        if (nums.size() == 0) return {-1};
        
        // Initialize two candidate variables and their respective counts
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

        // Phase 1: Find the candidates that may have a majority
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Phase 2: Verify the candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        // Check if any of the candidates occur more than n/3 times
        vector<int> result;
        if (count1 > nums.size() / 3) result.push_back(candidate1);
        if (count2 > nums.size() / 3) result.push_back(candidate2);

        // Return -1 if no majority element exists
        return result.empty() ? vector<int>{-1} : result;
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
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends