//
// Created by Lelana on 2026. 2. 28..
//

#ifndef LINEARDATASTRUCTURE_QUEUESTACK_STACK_H
#define LINEARDATASTRUCTURE_QUEUESTACK_STACK_H


template <typename T>
class Stack {
public:
    Stack() {

    }
    ~Stack()
    {

    }

    bool IsFull() const
    {
        return size == maxSize;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    Stack<T>* Push(T data)
    {
        datas[size] = data;
        ++size;

        return this;
    }
    Stack<T>* Push(T* data)
    {
        datas[size] = data;
        ++size;

        return this;
    }

    T Pop()
    {
        size--;
        return datas[size];
    }

private:
    static const int maxSize = 1024;
    int size = 0;
    T datas[maxSize];
};


#endif //LINEARDATASTRUCTURE_QUEUESTACK_STACK_H
