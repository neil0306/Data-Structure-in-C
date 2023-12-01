#include <string>
#include "double_queue.h"

bool is_palindrom(const string &str)
{
    char c1, c2;
    Queue<char> q1(100);

    // 所有元素入队列
    for (int i = 0; i < str.size(); i++){
        if(!q1.isFull()){
            q1.tail_enqueue(str[i]);
        }
    }

    // 出队 & 比较
    while(!q1.isEmpty()){           // 个数为偶数时, 从这里退出
        c1 = q1.head_dequeue();
        if(!q1.isEmpty()){          // 个数为奇数时, 从这里退出
            c2 = q1.tail_dequeue();
        }
        else{
            break;
        }

        // 判断读取的字符
        if (c1 == c2){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(void)
{
    string str;
    cout << "Please enter a string:" << endl;
    getline(cin, str);

    if (is_palindrom(str)){
        cout << str << " is a palindrom." << endl;
    }
    else{
        cout << str << " is NOT a palindrom." << endl;
    }

    return 0;
}