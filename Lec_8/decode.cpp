#include "queue.h"
#include <string>

using namespace std;

int main(void)
{
    Queue<char> q1;
    string code;
    cout << "Please enter your code: ";
    getline(cin, code);

    // 将输入的字符全部入队, 此时code里的内容可以废弃了
    for (int n = 0; n < code.size(); n++){
        q1.enqueue(code[n]);        // 内部包含了 isFull 判断
    }

    // 按规则解码
    int i = 0;
    while(!q1.isEmpty()){
        code[i++] = q1.dequeue();       // 奇数位置字符直接存入结果
        if(!q1.isEmpty()){              // 处理偶数位置字符
            char num = q1.dequeue();
            if(!q1.isFull()){
                q1.enqueue(num);        // 偶数位置字符重新入队
            }
        }
    }

    // 输出解码结果
    cout << "Original code is: ";
    for (int i = 0; i < code.size(); i++){
        cout << code[i];
    }
    cout << endl;
    return 0;
}