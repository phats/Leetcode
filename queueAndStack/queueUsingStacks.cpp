class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> s1,temp;
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size()>1 ){
            temp.push(s1.top());
            s1.pop();
        }
        int val=s1.top();
        s1.pop();
        while(!temp.empty()){
            s1.push(temp.top());
            temp.pop();
        }
        return val;
    }
    
    int peek() {
        while(s1.size()>1 ){
            temp.push(s1.top());
            s1.pop();
        }
        int val=s1.top();
        //s1.pop();
        while(!temp.empty()){
            s1.push(temp.top());
            temp.pop();
        }
        return val;
    }
    
    bool empty() {
        return (s1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */