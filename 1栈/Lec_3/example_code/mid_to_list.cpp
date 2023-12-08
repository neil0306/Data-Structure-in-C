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
    string str;
    int i, len;
    char temp;

    printf("Please enter a calculate expression: \n");
    getline(cin, str);

    len = str.size();
    Stack<char> myStack(len);
    for (i = 0; i < len; i++){
        if (str[i] == '('){
            continue;
        }
        else if (str[i] >= '0' && str[i] <= '9'){
            cout << str[i];
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
            myStack.push(str[i]);
        }
        else if(str[i] == ')'){
            myStack.pop(temp);
            cout << temp;
        }
    }
    cout << endl;
    return 0;
}
