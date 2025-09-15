class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(auto z: arr){
            if(z=="+"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                
                st.push(t2+t1);
            }
            else if(z=="-"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                
                st.push(t2-t1);
            }
            else if(z=="*"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                
                st.push(t2*t1);
            }
            else if(z=="/"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                int cal = (floor)((t2*1.0)/t1);
                st.push(cal);
            }
            else if(z=="^"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                
                st.push(pow(t2, t1));
            }
            else{
                st.push(stoi(z));
            }
            
        }
        return st.top();
    }
};