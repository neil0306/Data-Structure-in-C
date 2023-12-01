#ifndef __DOUBLE_QUEUE_H__
#define __DOUBLE_QUEUE_H__

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
        void head_enqueue(const T &t);
        T head_dequeue(void);
        void tail_enqueue(const T &t);
        T tail_dequeue(void);
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
void Queue<T>::head_enqueue(const T &t)
{
    if(!isFull()){
        head = (head - 1 + maxSIZE) % maxSIZE;
        items[head] = t;
    }
    else{
        cout << "Your Queue is FULL!" << endl;
    }
}

template <class T>
T Queue<T>::head_dequeue()
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

template<class T>
void Queue<T>::tail_enqueue(const T &t)
{
    if(!isFull()){
        items[tail] = t;
        tail = (tail + 1) % maxSIZE;
    }
    else{
        cout << "Your Queue is FULL!" << endl;
    }
}

template<class T>
T Queue<T>::tail_dequeue()
{
    T res;
    if(!isEmpty()){
        tail = (tail - 1 + maxSIZE) % maxSIZE;
        res = items[tail];
    }
    else{
        cout << "Your Queue is EMPTY!" << endl;
    }
    return res;
}

#endif // !__DOUBLE_QUEUE_H__
