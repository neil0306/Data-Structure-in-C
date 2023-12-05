#include <string>
#include "linklist_cpp.h"

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
    list1.print_linklist();
    cout << "middle node elment of list1 (even case): " << list1.find_mid() << endl;

    cout << "--------------" << endl;
    linklist<int> list2;
    list2.create_linklist(1);
    list2.create_linklist(2);
    list2.create_linklist(3);
    list2.create_linklist(4);
    list2.create_linklist(5);
    list2.create_linklist(6);
    list2.create_linklist(7);
    list2.create_linklist(8);
    list2.create_linklist(9);
    list2.print_linklist();
    cout << "middle node elment of list2 (odd case): " << list2.find_mid() << endl;
    return 0;
}
