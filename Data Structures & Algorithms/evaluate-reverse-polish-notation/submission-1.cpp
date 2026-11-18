class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st ;

        for(string s : tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int rightop = st.top();
                st.pop();
                int leftop = st.top();
                st.pop();

                if(s=="+")
                    st.push(leftop+rightop);
                else if(s=="-")
                    st.push(leftop-rightop);
                else if(s=="*")
                    st.push(leftop*rightop);
                else
                    st.push(leftop/rightop);
            }else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
