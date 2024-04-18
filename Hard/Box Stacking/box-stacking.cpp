//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
          vector<vector<int>> cuboids;

        for (int i = 0; i < n; i++) {
            cuboids.push_back({length[i], width[i], height[i]});
            cuboids.push_back({length[i], height[i], width[i]});
            cuboids.push_back({width[i], length[i], height[i]});
            cuboids.push_back({width[i], height[i], length[i]});
            cuboids.push_back({height[i], length[i], width[i]});
            cuboids.push_back({height[i], width[i], length[i]});
        }

        n = cuboids.size();
        vector<int> dp(n, 0);

        sort(cuboids.begin(), cuboids.end(), [&](vector<int> a, vector<int> b) {
            return (a[0] * a[1]) > (b[0] * b[1]);
        });

        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2]; 

            for (int j = 0; j < i; j++) {
                if (cuboids[i][0] < cuboids[j][0] && cuboids[i][1] < cuboids[j][1]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends