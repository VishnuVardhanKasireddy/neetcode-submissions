class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int m = st.empty() ? val : st.top().second;
        m = min(m,val);

        st.push({val,m});
    }
    
    void pop() {
        if(st.empty())
            return;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
