/*
 wk5_Linked_List_Functions_2_ivaldez.cxx

 Filename:       testCircBag.cpp
 Summary:        Demonstrate definition of a data structure that uses a circularly-linked list to store data
 Specifications: Design, define, implement and test a data structure that uses a circularly-linked list to store data.
                 The bag class will have a tail_ptr that is always either NULL or points to the same node as head_ptr.
                 The functions modified in the bag class are: insert(), print(), head_remove(), erase(), count(), listLength() and listClear()
                 The functions modified in the link-list toolkit are: list_length(), list_head_insert(), list_head_remove(), list_search() and list_clear()
                 Program will then test these functions that manipulate the linked list.
 Test cases:     20 random integers, four 5 integers, six 3 integers.

 Author:         Isaias Valdez
 Created:        November 1, 2022
 Summary of Modifications:
 */

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "circBag.h" // With Item defined as an int
#include <time.h>

using namespace std;
using namespace main_savitch_5;

int main( )
{
    srand(time(NULL));
    circBag cb1;
    circBag::size_type manyRemoved;
    circBag::size_type numOfEntries;
    std::size_t length;

    for (int i = 0; i < 20; i++){
        cb1.insert(rand() % 20 + 1);
    }
    for (int i = 0; i < 4; i++){
        cb1.insert(5);
    }
    cout << "Printing data values from the linked list...\n";
    cb1.print();
    cout << "Number of nodes: " << cb1.size() << endl << endl;

    cout << "Testing remove_head() function..." << endl;
    cb1.head_remove();
    cb1.print();
    cout << "Number of nodes: " << cb1.size() << endl << endl;

    cout << "Testing the erase() function by erasing all 5's from the list..." << endl;
    manyRemoved = cb1.erase(5);
    cb1.print();
    cout << "Number of 5's removed: " << manyRemoved << endl << endl;

    cout << "Testing the count function by adding six 3's to the list and counting up\n"
         << "the total number of 3's in the list...\n";
    for (int i = 0; i < 6; i++)
        {
        cb1.insert(3);
        }
    cb1.print();
    numOfEntries = cb1.count(3);
    cout << "Number of 3's in the list: " << numOfEntries << endl << endl;

    cout << "Testing the listLength() function...\n";
    length = cb1.listLength();
    cout << "List length: " << length << endl << endl;

    cout << "Testing the listClear() function...\n";
    cb1.listClear();
    cb1.print();
    cout << "Number of nodes: " << cb1.size() << endl << endl;
    return 0;
}
