//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int ans=1;
      
      bool zero=false;
      
      int cnt=0;
         for(auto it:nums){
          
          if(it==0){
              cnt++;
        
      }
         }
         
         vector<long long int>res(nums.size(),0);
           if(cnt>=2){
          return res;
          
      }
      for(auto it:nums){
          
          if(it==0){
              zero=true;
             
              continue;
          }
          ans=ans*it;
      }
      

      vector<long long int>answer;
      

      if(zero){
          
         for(auto it:nums){
          
          
         if(it==0){
          
          answer.push_back(ans);   
         }
         else
          answer.push_back(0);
      }  
      }
      else{
      
      for(auto it:nums){
          
        
          answer.push_back(ans/it);
      }
      }
      return answer;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends