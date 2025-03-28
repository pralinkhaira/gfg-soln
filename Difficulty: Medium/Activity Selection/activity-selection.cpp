//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        // code here
        int n=start.size();
        vector<pair<int,int>>store;
        for(int i=0;i<n;i++){
            store.push_back({start[i],end[i]});
        }
        
        sort(store.begin(),store.end());
        int maxi=1;
        int activity=1;
        int s=-1,e=-1;
        for(int i=0;i<n;i++){
            int first=store[i].first,second=store[i].second;
            if(s==-1 && e==-1){
                s=first,e=second;
            } else if(first>e){
                activity++;
                maxi=max(maxi,activity);
                s=first,e=second;
            } else if(first<=e){
                s=max(s,first),e=min(e,second);
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends