#include "linklist_cpp.h"
#include <iostream>

using namespace std;

int main(void)
{
    linklist<int> list1;
    list1.create_linklist(1);
    list1.create_linklist(2);
    list1.create_linklist(3);
    list1.create_linklist(4);
    list1.create_linklist(5);
    list1.create_linklist(6);
    list1.create_linklist(7);
    list1.create_linklist(8);
    list1.create_linklist(9);
    list1.create_linklist(10);
    cout << "Original: ";
    list1.print_linklist();
    cout << "After reverse: ";
    list1.reverse();
    list1.print_linklist();
    return 0;
}