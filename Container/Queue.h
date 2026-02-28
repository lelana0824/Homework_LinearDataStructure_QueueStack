//
// Created by Lelana on 2026. 2. 28..
//

#ifndef LINEARDATASTRUCTURE_QUEUESTACK_QUEUE_H
#define LINEARDATASTRUCTURE_QUEUESTACK_QUEUE_H


template <typename T, size_t inSize = 512>
class Queue {
public:
    Queue()
        :front(0), rear(0), size(inSize + 1)
    {};
    ~Queue(){};

    bool Enqueue(T inData) {
        if (IsFull()) return false;

        data[rear] = inData;
        rear = (rear + 1) % size;

        return true;
    }

    bool Enqueue(T* inData) {
        if (IsFull()) return false;

        data[rear] = inData;
        rear = (rear + 1) % size;

        return true;
    }

    T Dequeue() {
        T rData = data[front];
        data[front] = T();

        front = (front + 1) % size;
        return rData;
    }

    bool IsEmpty() const {
        return front == rear;
    }

    bool IsFull() const {
        return (rear + 1) % size == front;
    }

    T Peek() {
        return data[front];
    }

    int Size() const {
        return inSize;
    }
private:
    int front;
    int rear;
    int size;

    T data[inSize + 1];
};


#endif //LINEARDATASTRUCTURE_QUEUESTACK_QUEUE_H