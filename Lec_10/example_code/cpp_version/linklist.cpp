#include <string>
#include "linklist_cpp.h"

int main(void)
{
    linklist<char> list;
    list.create_linklist('A');
    list.create_linklist('B');
    list.create_linklist('C');
    list.create_linklist('D');
    list.print_linklist();
    cout << "----------" << endl;

    list.delete_node(0);
    list.print_linklist();

    cout << "-----\n";
    list.insert_node(0, 'F');
    list.insert_node(2, 'Z');
    list.print_linklist();

    cout << "------" << endl;
    if(list.search('C')){
        cout << "The element is found in the linklist." << endl;
    }
    else{
        cout << "Cannot find it." << endl;
    }

    cout << "-------------------------" << endl;
    cout << "-------------------------" << endl;

    linklist<string> list_str;          // 换个类型试试
    list_str.create_linklist("A");
    list_str.create_linklist("B");
    list_str.create_linklist("C");
    list_str.create_linklist("D");
    list_str.print_linklist();
    cout << "----------" << endl;

    list_str.delete_node(0);
    list_str.print_linklist();

    cout << "-----\n";
    list_str.insert_node(0, "F");
    list_str.insert_node(2, "Z");
    list_str.print_linklist();

    cout << "------" << endl;
    if(list_str.search("C")){
        cout << "The element is found in the linklist." << endl;
    }
    else{
        cout << "Cannot find it." << endl;
    }
    return 0;
}