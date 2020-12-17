class MyCircularQueue {

private:
    int front, rear;
    int* queue;
    int size, cap;
public:
    MyCircularQueue(int k) {
        front = 0;
        rear = 0;
        size = 0;
        cap = k;
        queue = (int*)malloc(sizeof(int) * (k + 1));
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        queue[rear] = value;
        rear = (rear + 1) % (cap + 1);
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % (cap + 1);
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return queue[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        if (rear == 0) return queue[cap];
        return queue[rear - 1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};