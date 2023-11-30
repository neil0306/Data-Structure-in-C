#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
    int num;
    int temp;
    Stack<int> myStack(100);

    cout << "Please enter an integer in decimal: \n";
    cin >> num;

    while (num != 0){
        myStack.push(num % 2);
        num /= 2;
    }

    while(!myStack.isEmpty()){
        myStack.pop(temp);
        cout << temp;
    }
    cout << endl;
    return 0;
}
