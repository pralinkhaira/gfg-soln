//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        
        int min_price =  INT_MAX;
        
        int max_profit =  0;
        
        
        for (int price : prices){
            
            if(price < min_price){
                min_price =  price;
                
            }
            
            int profit =  price - min_price;
            
            if (profit > max_profit){
                max_profit =  profit;
            }
        }
        
        return max_profit;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends