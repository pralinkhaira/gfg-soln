//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
  double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        // sort(arr,arr+n);
        double ans =0;
        vector<pair<double,double>>v;
        for(int i =0;i<n;i++){
            v.push_back({double(arr[i].value)/arr[i].weight,arr[i].weight});
        }
        sort(v.rbegin(),v.rend());
        for(int i = 0;i<n;i++){
            if(v[i].second<=w){
                ans+=(v[i].first)*v[i].second;
                w -= v[i].second;
            }
            else{
                ans+=((v[i].first))*w;
                w=0;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends