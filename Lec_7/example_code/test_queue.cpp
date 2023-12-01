#include "queue.h"

int main(void)
{
    // test full
    Queue<int> q1(1);
    cout << "isFull: " << (q1.isFull() == true ? "true" : "false") << ": ";
    q1.enqueue(1);

    // test empty
    Queue<char> q2(100);
    cout << "isEmpty: " << (q2.isEmpty() == true ? "true" : "false") << ": ";
    q2.dequeue();

    // 出入队列
    char c = 'A';
    for (int i = 0; i < 3; i++)
    {
        if(!q2.isFull()){
            q2.enqueue(c);
            c++;            // 编程 ASCII 码之后, ++ 操作就会顺延一个字符, 变成 B
        }
    }

    while(!q2.isEmpty()){
        cout << q2.dequeue();
    }
    cout << endl;

    return 0;
}