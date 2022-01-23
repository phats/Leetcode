class MyCircularQueue {
public:
    vector<int> arr;
    int head,tail;
    int currSize;
    MyCircularQueue(int k) {
        arr.resize(k,-1);
        head=tail=-1;
        currSize=0;
    }
    
    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        else{
            if (head==-1){
                head=0;
            }
            tail=(tail+1)%arr.size();
            arr[tail]=value;
            currSize++;
            return true;
        }
    }
    
    bool deQueue() {
        if (isEmpty()){
            return false;
        }
        else{
            arr[head]=-1;
            head=(head+1)%arr.size();
            currSize--;
            return true;
        }
    }
    
    int Front() {
        if (head==-1) return -1;
        return arr[head];
    }
    
    int Rear() {
        if (tail==-1) return -1;
        return arr[tail];
    }
    
    bool isEmpty() {
        return (currSize==0);
    }
    
    bool isFull() {
        return (currSize==arr.size());
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */