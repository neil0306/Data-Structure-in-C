#include <iostream>
#include <string>

using namespace std;
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

int main(void)
{
    string a;
    char temp;
    int n;
    int i;
    int n1, n2;
    int result;

    cout << "Please enter a reverse polish expression: " << endl;
    getline(cin, a);

    n = a.size();
    Stack<int> myStack(n);

    for (i = 0; i < n; i++){
        if (a[i] >= '0' && a[i] <= '9'){  // 输入操作数时, 目前只考虑个位数
            myStack.push(a[i] - '0');
        }
        else{   
            // 注意出栈顺序, 这会影响计算结果. 由于栈是后入先出, 所以先出栈的是第二个操作数, 第一个操作数排在后面
            myStack.pop(n2);
            myStack.pop(n1);
            switch (a[i])       // 根据不同操作符执行不同的出栈操作
            {
            case '+':
                myStack.push(n1 + n2);
                break;
            case '-':
                myStack.push(n1 - n2);
                break;
            case '*':
                myStack.push(n1 * n2);
                break;
            default:
                break;
            }
        }
    }

    myStack.pop(result);
    cout << "result = " << result << endl;

    return 0;
}
