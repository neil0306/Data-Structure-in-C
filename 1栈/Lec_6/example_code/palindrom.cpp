#include <iostream>
#include <string>
using namespace std;

// --------- 用模板类实现简单的栈 -----------
// 实现栈结构主要由两部分: 数组 + 循环
//  核心就是管理好数组的存取, 以及防止内存泄露
template<class T>
class Stack
{
    private:
        int max_cap;    // 栈大小
        int top;        // 栈顶指针
        T * items;      // 存放栈元素的数组
    public:
        Stack(int m)
        {
            max_cap = m;
            top = 0;
            items = new T[max_cap];
        }
        ~Stack(){delete [] items;}

        bool isFull(void);          // 判断栈是否为满
        bool isEmpty(void);         // 判断栈是否为空
        bool push(const T &t);            // 压栈/入栈
        bool pop(T &t);             // 出栈
        void show();
};

template <class T>
bool Stack<T>::isEmpty()
{
    return top == 0;
}

template <class T>
bool Stack<T>::isFull()
{
    return top == max_cap;
}

template <class T>
bool Stack<T>::push(const T &t)
{
    if (top < max_cap && !isFull()){
        items[top++] = t;
        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool Stack<T>::pop(T &t)
{
    if (top > 0 && !isEmpty()){
        t = items[--top];
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void Stack<T>::show()
{
    if (!isEmpty()){
        int temp = top;
        while (temp > 0){
            cout << items[--temp];
        }
        cout << endl;
    }
    else{
        cout << "Sorry, Stack is Empty!" << endl;
    }
}


bool is_palindrom(string &s)
{
    int i;
    Stack<char> myStack(512);
    if(s.size() == 0 || s == " "){
        return 0;
    }

    for (i = 0; i < s.size()/2; i++){
        myStack.push(s[i]);
    }

    if(s.size() % 2 == 1){        // 奇数
        i++;
    }

    while(!myStack.isEmpty()){
        char temp;
        myStack.pop(temp);
        if (temp == s[i]){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    string str;
    cout << "Please enter a string: " << endl;
    getline(cin, str);

    if(is_palindrom(str)){
        cout << "Your input string is palindrom." << endl;
    }
    else{
        cout << "Your input string is NOT palindrom." << endl;
    }
    return 0;
}
