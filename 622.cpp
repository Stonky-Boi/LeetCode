class MyCircularQueue {
private:
    vector<int> queue;
    int front,rear;
    int count;
public:
    MyCircularQueue(int k) {
        queue=vector<int>(k,0);
        front=0;
        rear=0;
        count=0;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        queue[rear]=value;
        rear=(rear+1)%queue.size();
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        front=(front+1)%queue.size();
        count--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:queue[front];
    }
    
    int Rear() {
        return isEmpty()?-1:queue[(rear-1+queue.size())%queue.size()];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==queue.size();
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