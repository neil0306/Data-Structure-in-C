#include "linklist_cpp.h"
#include <iostream>


using namespace std;

int main(void)
{
    linklist<int> list1;
    int n;
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
    cout << "Please enter the last node index you want to find: " << endl;
    cin >> n;
    cout << "the last n: " << list1.find_last_nth(n) << endl;

    return 0;
}