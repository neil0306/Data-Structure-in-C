#include <string>
#include "linklist_cpp.h"

int main(void)
{
    linklist<int> list1;
    list1.create_linklist(1);
    list1.create_linklist(2);
    list1.create_linklist(8);
    list1.create_linklist(2);
    list1.create_linklist(3);
    list1.create_linklist(9);
    list1.create_linklist(4);
    list1.create_linklist(6);
    list1.create_linklist(4);
    list1.create_linklist(8);
    list1.create_linklist(7);
    list1.create_linklist(5);
    list1.create_linklist(2);
    list1.create_linklist(9);
    list1.create_linklist(6);
    list1.print_linklist();
    cout << "-------------" << endl;

    list1.delete_repeat();
    list1.print_linklist();
    cout << "-------------" << endl;
    return 0;
}