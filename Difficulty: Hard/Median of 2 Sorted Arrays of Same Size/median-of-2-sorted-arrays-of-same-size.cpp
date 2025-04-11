//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        vector<int>nums1=a;
        vector<int>nums2=b;
         if(nums1.size() > nums2.size()) 
        return medianOf2(nums2, nums1);

    int n1 = nums1.size(), n2 = nums2.size();
    int low = 0, high = n1;

    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if(l1 <= r2 && l2 <= r1) {
            if((n1 + n2) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }
        else if(l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return 0.0; // won't reach here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOf2(array1, array2);
        int converted = static_cast<int>(ans);
        if (converted == ans) {
            cout << converted << endl;
        } else {
            cout << fixed << setprecision(1) << ans << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends