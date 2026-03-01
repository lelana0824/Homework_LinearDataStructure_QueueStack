//
// Created by Lelana on 2026. 3. 1..
//

#ifndef LINEARDATASTRUCTURE_QUEUESTACK_VECTOR_H
#define LINEARDATASTRUCTURE_QUEUESTACK_VECTOR_H

const int initSize = 4;
template<typename T>
class Vector {
public:
    Vector(): size(0), capacity(initSize) {
        list = new T[capacity];
    }
    ~Vector() {
        if (list) {
            delete[] list;
        }

    }
/*
*- at(integer i) : index i에 대해서 데이터 값을 반환해준다.
    - operator[](int index);
- set(integer i, object o) : index i의 데이터를 o로 바꿔준다.
    - operator[](int index);
- insert/pushback/emplace(integer i, object o) : index i에 o를 삽입한다.
- erase(integer i) : index i에 있는 데이터를 제거해준다.
- size() : 벡터의 크기를 반환해준다.
- empty() : 벡터가 비었는지를 알려준다.
 *
 */
    T at(int i) {
        return list[i];
    }

    void Set(int i, T value) {
        if (!list[i]) {
            size++;
        }
        list[i] = value;
    }

    void Insert(T value) {
        if (IsFull()) {
            PowerSize();
        }

        for (int i = size - 1; i >= 0; i--) {
            list[i + 1] = list[i];
        }
        list[0] = value;
        size++;
    }

    void Pushback(T value) {
        if (IsFull()) {
            PowerSize();
        }

        list[size++] = value;
    }

    // 데이터의 연속성을 지켜야 함.
    void Erase(int i) {
        for (int j = size - 1; j > i; j--) {
            list[j - 1] = list[j];
        }

        size--;
    }

    int Size() const { return size; }

    bool IsEmpty() const {
        return size == 0;
    }

private:
    bool IsFull() const {
        return size == capacity;
    }
    void PowerSize() {
        // 현재 리스트 사이즈를 2배로 바꾸고 요소를 모두 옮긴다.
        capacity *= 2;

        T* newList = new T[capacity];

        for (int i = 0; i < size; i++) {
            newList[i] = list[i];
        }

        delete[] list;
        list = newList;
    }

private:
    int capacity;
    int size;
    T* list = nullptr;
};

#endif //LINEARDATASTRUCTURE_QUEUESTACK_VECTOR_H