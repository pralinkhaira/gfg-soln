class Solution {
  public:
    vector<int> nextSmaller(int n, vector<int> &arr){
        vector<int> nsi(n, n);
        
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while((!st.empty()) && (arr[st.top()]>=arr[i]))
              st.pop();
            if(st.empty())
              nsi[i] = n;
            else
             nsi[i] = st.top();
            
            
            st.push(i); 
        }
        
        return nsi;
    }
    vector<int> prevSmaller(int n, vector<int> &arr){
        vector<int> psi(n, -1);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            while((!st.empty()) && (arr[st.top()]>=arr[i]))
              st.pop();
            if(st.empty())
              psi[i] = -1;
            else
             psi[i] = st.top();
            
            
            st.push(i); 
        }
        
        return psi;
    }
  
    vector<int> findWidth(int n, vector<int> &arr){
        vector<int> nsi = nextSmaller(n, arr);
        vector<int> psi = prevSmaller(n, arr);
        
        vector<int> width(n, 0);
        for(int i=0;i<n;i++){
            width[i] = nsi[i] - psi[i] - 1;
        }
        return width;
    }
  
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;
        
        vector<int> arr(m, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                  arr[j] = 0;
                else
                  arr[j]++;
            }
            
            
            vector<int> width = findWidth(m, arr);
            
            for(int k=0;k<m;k++){
                ans = max(ans, width[k]*arr[k]);
            }
            
            
            
            
        }
        return ans;
    }
};