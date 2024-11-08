#ifndef QUEUE2__CPP
#define QUEUE2__CPP

#include <bits/stdc++.h>

template<class T>
class Node {
    T elem;
    Node<T>* next;

  public:
    Node(T x, Node<T>* a = nullptr) {
        elem = x;
        next = a;
    }

    T& getElem() {
        return elem;
    }

    void setNext(Node* a) {
        next = a;
    }

    Node<T>* getNext() {
        return next;
    }
};

template<class T>
class Queue {
    int num;
    Node<T>* first;
    Node<T>* last;

  public:
    Queue() {
        num = 0;
        first = last = nullptr;
    }

    bool empty() {
        return num == 0;
    }

    int size() {
        return num;
    }

    T& front() {
        return first->getElem();
    }

    T& back() {
        return last->getElem();
    }

    void push(T x) {
        if (num == 0) {
            first = last = new Node<T>(x);
        } else {
            last->setNext(new Node<T>(x));
            last = last->getNext();
        }
        num++;
    }

    void pop() {
        if (num == 0) return;
        first = first->getNext();
        num--;
    }
};

#endif
