#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using namespace std;

template<class T>
class Queue
{
    private:
        int head;
        int tail;
        int maxSIZE;
        T * items;
    public:
        Queue()
        {
            maxSIZE = 512;
            head = tail = 0;
            items = new T[maxSIZE];
        }
        Queue(int m) : maxSIZE(m)
        {
            items = new T[maxSIZE];
            head = tail = 0;
        }
        ~Queue(){delete [] items;}

        bool isFull();
        bool isEmpty();
        void enqueue(const T &t);
        T dequeue(void);
};

template< class T>
bool Queue<T>::isEmpty()
{
    return head == tail;
}

template <class T>
bool Queue<T>::isFull()
{
    return (tail+1) % maxSIZE == head;
}

template <class T>
void Queue<T>::enqueue(const T &t)
{
    if(!isFull()){
        items[tail] = t;
        tail = (tail+1) % maxSIZE;
    }
    else{
        cout << "Your Queue is FULL!" << endl;
    }
}

template <class T>
T Queue<T>::dequeue()
{
    T res;
    if (!isEmpty()){
        res = items[head];
        head = (head + 1) % maxSIZE;
    }
    else{
        cout << "Your Queue is EMPTY!" << endl;
    }
    return res;
}

#endif // !__QUEUE_H__
