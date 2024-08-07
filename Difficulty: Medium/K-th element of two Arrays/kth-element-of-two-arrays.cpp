//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  void merge(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3){
      int i  = 0;
      int j = 0;
    //   int k = 0;
     int n = arr1.size();
     int m = arr2.size();
     while(i<n && j < m){
         if(arr1[i] < arr2[j]){
             arr3.push_back(arr1[i]);
             i++;
         }
         else{
            arr3.push_back(arr2[j]);
            j++;
         }
         
     }
     while(i < n){
         arr3.push_back(arr1[i]);
        //  k++;
         i++;
         
     }
     while(j < m){
         arr3.push_back(arr2[j]) ;
        //  k++;
         j++;
         
     }
      
  };
  
  
  
  
  
  
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        // set<int> st; 
    //     map<int, int>mp1;
    //     map<int,int> mp2;
    //     for(int i = 0; i< arr1.size(); i++){
    //         mp1[arr1[i]]++;
            
    //     }
    //     for(int j = 0; j< arr2.size(); j++){
    //         mp2[arr2[j]]++;
            
    //     }
    //     vector<int> ans;
    //     int m = (arr1.size() + arr2.size());
        
       
    //     for(auto& element: mp1){
    //       ans.push_back(element.first);
    //     }
        
    //   for(auto& itr: mp2){
    //       ans.push_back(itr.first);
           
    //   }
    //   sort(ans.begin(), ans.end());
    //   for(int i = 0; i<m-1; i++){
    //       if(i == k){
    //           return ans[i];
    //       }
    //   }
    //   return 0;
    vector<int> arr3;
    merge(arr1, arr2, arr3);
    
          return arr3[k-1];
    
  
    
   
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends