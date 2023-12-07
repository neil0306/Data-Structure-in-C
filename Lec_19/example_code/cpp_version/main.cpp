#include "dul_linklist_cpp.h"
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
    list1.print_linklist();

    cout << "-------" << endl;
    list1.insert_node(0, 11);
    list1.print_linklist();

    list1.delete_node(6);
    list1.print_linklist();

    list1.delete_node(0);
    list1.print_linklist();

    list1.delete_node(0);
    list1.print_linklist();

    list1.delete_node(4);
    list1.print_linklist();

    list1.insert_node(0, 8);
    list1.print_linklist();

    list1.insert_node(5, 9);
    list1.print_linklist();

    list1.insert_node(2, 13);
    list1.print_linklist();

    cout << "Seach result: " << (list1.search(2) == true ? "true" : "false") << endl;

    cout << "------------" << endl;

    list1.reverse_print();
    return 0;
}