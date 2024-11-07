//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        long long pleft[n];
        long long pright[n];
        
       
        pleft[0]=arr[0];
        
        for(int i=1;i<n;i++){
            
            pleft[i]= arr[i]+pleft[i-1];
        }
        
        if(pleft[n-1]%3!=0)
        return {-1,-1};
        
        
        
        pright[n-1]=arr[n-1];
        
        
        for(int i=n-2;i>=0;i--)
        pright[i]=arr[i]+pright[i+1];
        
        
        // for(int i=0;i<n;i++)
        // cout<<pleft[i]<<" ";
        
        // cout<<endl;
        
        
        // for(int i=0;i<n;i++)
        // cout<<pright[i]<<" ";
        
        // cout<<endl;
        
        
        
        
        int i=0, j=n-1;
        
        long long sum=pleft[n-1];
        vector<int> ans;
        
        
        while(i<=j){
            
            if((pleft[i]==pright[j]) && (pleft[i]==(sum-pleft[i]-pright[j]))){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            
            else if(pright[j]>pleft[i])
            i++;
            else
            j--;
            
        }
        
        if(ans.size()>0)
        return ans;
        else
        return {-1,-1};
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends