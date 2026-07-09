class MinStack {
public:
    stack<int> main;
    stack<int> minimums;

    MinStack() {}
    
    void push(int val) {
        main.push(val);
        if(minimums.empty() || minimums.top() > val){
            minimums.push(val);
        }else{
            minimums.push(minimums.top());
        }
    }
    
    void pop() {
        main.pop();
        minimums.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minimums.top();
    }
};
