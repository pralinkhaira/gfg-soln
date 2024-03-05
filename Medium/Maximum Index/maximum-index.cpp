//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:

    int maxIndexDiff(int a[], int n) 
    { 
        vector<int> leftMin(n), rightMax(n);

        leftMin[0] = a[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], a[i]);
        }
    
        rightMax[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], a[i]);
        }
    
        int i = 0, j = 0, maxDiff = INT_MIN;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                maxDiff = max(maxDiff, j - i);
                j++;
            } else {
                i++;
            }
        }
    
        return maxDiff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends