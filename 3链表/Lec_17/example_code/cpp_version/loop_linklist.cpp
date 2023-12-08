#include "loop_linklist_cpp.h"
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
    list1.print_linklist();

    cout << "--------" << endl;
    list1.insert_node(0, 11);
    list1.print_linklist();

    cout << "--------" << endl;
    list1.delete_node(1);
    list1.print_linklist();

    cout << "--------" << endl;
    list1.delete_node(0);
    list1.print_linklist();

    cout << "--------" << endl;
    list1.delete_node(0);
    list1.print_linklist();

    cout << "--------" << endl;
    list1.delete_node(1);
    list1.print_linklist();

    cout << "--------" << endl;
    list1.insert_node(0, 8);
    list1.print_linklist();

    cout << "--------" << endl;
    list1.insert_node(5, 9);
    list1.print_linklist();

    cout << "--------" << endl;
    list1.insert_node(2, 13);
    list1.print_linklist();

    cout << (list1.search(9) == true? "found." : "Not found.") << endl;
    return 0;
}