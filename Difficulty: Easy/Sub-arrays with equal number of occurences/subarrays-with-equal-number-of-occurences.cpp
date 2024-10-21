//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x)arr[i]=1;
            else if(arr[i]==y)arr[i]=-1;
            else arr[i]=0;
        }
        unordered_map<int,int>m;
        int sum=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];
            if(sum==0){
                count++;
            }
            if(m.find(sum)!=m.end()){
                count=count+m[sum];
            }
            m[sum]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends