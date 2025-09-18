class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        vector<int>t=arr;
        for(auto it:arr)t.push_back(it);
        stack<int>st;
        st.push(t[t.size()-1]);
        vector<int>ans(arr.size(),-1);
        for(int i=t.size()-2;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=t[i])st.pop();
            if(i<arr.size()&&!st.empty())ans[i]=st.top();
            st.push(t[i]);
        }
        return ans;
    }
};