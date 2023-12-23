//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>

struct Stock {
    int price;
    int day;
    
    static bool compareStocks(const Stock &a, const Stock &b) {
        return a.price < b.price;
    }
};

class Solution {
public:

    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<Stock> stocks;
    
        for (int i = 0; i < n; ++i) {
            stocks.push_back({price[i], i + 1});
        }
    
        sort(stocks.begin(), stocks.end(), Stock::compareStocks);
    
        int totalStocks = 0;
    
        for (const auto &stock : stocks) {
            int stocksToBuy = min(k / stock.price, stock.day);
            totalStocks += stocksToBuy;
            k -= stock.price * stocksToBuy;
        }
    
        return totalStocks;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends