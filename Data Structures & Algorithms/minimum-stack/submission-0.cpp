class MinStack {
public:

    stack<int> main_stack;
    stack<int> track_stack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        main_stack.push(val);

        if (track_stack.empty() == true){
            track_stack.push(val);
        }

        else if (val <= track_stack.top()){
            track_stack.push(val);
        }
    }
    
    void pop() {
        if (track_stack.top() == main_stack.top()){
            track_stack.pop();
        }

        main_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return track_stack.top();
    }
};
