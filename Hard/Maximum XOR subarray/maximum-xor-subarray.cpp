//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{  
    struct node{
        int val;
        node* left;
        node* right;
        
        node()
        {
            left = NULL;
            right = NULL;
        }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        node* root = new node();
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int temp = nums[i];
            int mask = 1<<30;
            node* ptr = root;
            for(int j=0;j<31;j++)
            {
                if(mask & temp)
                {
                    node* temp_node;
                    if(!ptr->right){
                        temp_node = new node();
                        ptr->right = temp_node;
                    }
                    // cout<<"1";
                    ptr = ptr->right;
                }
                else
                {
                    node* temp_node;
                    if(!ptr->left){
                        // cout<<"0";
                        temp_node = new node();
                        ptr->left = temp_node;
                    }
                    // cout<<"0";
                    ptr = ptr->left;
                }
                mask = mask>>1;
            }
            // ptr = new node();
            ptr->val = temp;
             // cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            int temp = nums[i];
            int mask = 1<<30;
            node* ptr = root;
            for(int j=0;j<31;j++)
            {
                if(mask & temp){
                    if(ptr->left)
                        ptr = ptr->left;
                    else
                        ptr = ptr->right;
                }
                else{
                    if(ptr->right)
                        ptr = ptr->right;
                    else
                        ptr = ptr->left;
                }
                mask = mask>>1;
            }
            // cout<<(ptr->val)<<" ";
            ans = max(ans,(ptr->val^temp));
        }
        return ans;
    }
public:
    int maxSubarrayXOR(int N, int arr[]){    
        //code here
        vector<int>v;
        v.push_back(0);
        for(int i=0;i<N;i++){
            v.push_back(arr[i]^v[i]);
            // cout<<
        }
        return findMaximumXOR(v);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends