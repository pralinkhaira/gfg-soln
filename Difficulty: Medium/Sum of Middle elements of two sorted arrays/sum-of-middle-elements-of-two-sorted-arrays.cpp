//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    void mergeArray(vector<int>& a1, vector<int>& a2, vector<int>& ans) {
        int n1 = a1.size(), n2 = a2.size();
        int i = 0, j = 0, k = 0; 
    
        // Merge both arrays using two-pointer technique
        while (i < n1 && j < n2) {
            if (a1[i] < a2[j]) {
                ans[k++] = a1[i++];
            } else {
                ans[k++] = a2[j++];
            }
        }

        // Add remaining elements of a1 (if any)
        while (i < n1) {
            ans[k++] = a1[i++];
        }

        // Add remaining elements of a2 (if any)
        while (j < n2) {
            ans[k++] = a2[j++];
        }
    }

    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> ans(n1 + n2);  
        mergeArray(arr1, arr2, ans);
        int mid = ans.size() / 2;
        return ans[mid - 1] + ans[mid]; 
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl << "~\n";
    }
}
// } Driver Code Ends