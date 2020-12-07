class MyCircularDeque {
public:
    
    int* arr;
    int front, back, size, cap;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        arr = (int*)malloc(sizeof(int) * (2 * k + 2));
        front = k, back = k + 1;
        size = 0;
        cap = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        size++;
        arr[front] = value;
        front--;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        size++;
        arr[back] = value;
        back++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        size--;
        front++;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        size--;
        back--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front + 1];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return arr[back - 1];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (front + 1 == back) return true;
        return false;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if (size == cap) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */