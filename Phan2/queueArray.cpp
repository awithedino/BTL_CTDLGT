#include <bits/stdc++.h>
#ifndef QUEUE__CPP
#define QUEUE__CPP
using namespace std;

template<class T>
class Queue {
  private:
    int num, cap, first, last;
    T* arr;

  public:
    Queue() {
        num = cap = first = last = 0;
        arr = nullptr;
    }

    ~Queue() {
        if (arr)
            delete[] arr;
    }

    int size() {
        return num;
    }

    bool empty() {
        return num == 0;
    }

    T& front() {
        return arr[first];
    }

    T& back() {
        return (last == 0 ? arr[cap - 1] : arr[last - 1]);
    }

    void pop() {
        first = (first + 1) % cap;
        num--;
    }

    void push(T x) {
        if (num == cap) {
            cap = (1 + cap) * 2;
            T* temp = new T[cap];
            for (int i = 0, j = first; i < num; j++, i++) {
                temp[i] = arr[j % cap];
            }
            if (arr) 
                delete[] arr;
            arr = temp;
            first = 0;
            last = num;
        }
        arr[last] = x;
        last = (last + 1) % cap;
        num++;
    }
};

#endif
