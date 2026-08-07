class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < operations.size(); i++) {

            if (operations[i] == "+") {
                if (!st.empty()){
                    int top1=st.top();
                    int top2=0;
                    st.pop();
                    if (!st.empty()){
                        top2=st.top();
                    }
                    st.push(top1);
                    st.push(top1+top2);
                    
                }
                
                
            } 
            else if (operations[i] == "D") {
                if (!st.empty()){
                    st.push(st.top()*2);      
                }
            } 
            else if (operations[i] == "C") {
                st.pop();

            } else {
                st.push(stoi(operations[i]));
            }
        }
        while (!st.empty()) {
           ans+= st.top();
           st.pop();
        }
        return ans;
    }
};