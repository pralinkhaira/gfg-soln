//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void placeNQueen(vector<vector<int>>& ans,
                     vector<int>& sol,
                     int row,int n,
                     vector<bool>& columns_record,
                     vector<bool>& left_diagonal_record,
                     vector<bool>& right_diagonal_record){
        
        
        //base case
        if(row==n){
            ans.push_back(sol);
            return;
        }
        
        
        //iterate over all columns
        for(int col=0;col<n;col++){
            if(columns_record[col]==false &&
               left_diagonal_record[row-col+n-1]==false &&
               right_diagonal_record[row+col]==false
            ){
                columns_record[col] = true;
                left_diagonal_record[row-col+n-1] = true;
                right_diagonal_record[row+col]=true;
                sol.push_back(col+1);
                placeNQueen(ans,sol,row+1,n,columns_record,left_diagonal_record,right_diagonal_record);
                columns_record[col] =  left_diagonal_record[row-col+n-1] = right_diagonal_record[row+col]=false;
                sol.pop_back();
                
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        
        //create a vector to store every possible ans
        vector<int> sol;
        
        vector<bool> columns_record(n,false),
                     left_diagonal_record((2*n) -1 ,false),
                     right_diagonal_record((2*n) -1 ,false);
                     
        
        placeNQueen(ans,sol,0,n,columns_record,left_diagonal_record,right_diagonal_record);
        
        return ans;
        
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends