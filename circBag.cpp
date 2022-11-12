// FILE: circBag.cpp
// CLASS implemented: circBag.h
// INVARIANT for the bag ADT:
//   1. The items in the circBag are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//      many_nodes.

#include <iostream>
#include <cassert>  // Provides assert
#include <cstdlib>  // Provides NULL, rand, size_t
#include "cNode.h"  // Provides node and the linked list functions
#include "circBag.h"
using namespace std;

namespace main_savitch_5
{

    circBag::circBag( )
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;
	many_nodes = 0;
    }

    circBag::circBag(const circBag& source)
    // Library facilities used: node1.h
    {

      //  list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
    }

    circBag::~circBag( )
    // Library facilities used: node1.h
    {
        list_clear(head_ptr, tail_ptr);
        many_nodes = 0;
    }

    //counts the number of times a value appears in the list
    circBag::size_type circBag::count(const value_type& target) const
    // Library facilities used: cstdlib, node1.h
    {
	size_type answer;
	const node *cursor; // Use const node* since we don't change the nodes.

	answer = 0;
	cursor = list_search(head_ptr, tail_ptr, target);
	while (cursor != NULL)
	{
	    // Each time that cursor is not NULL, we have another occurrence of
	    // target, so we add one to answer, and move cursor to the next
	    // occurrence of the target.
	    ++answer;
	    cursor = cursor->link( );
	    cursor = list_search(cursor, tail_ptr, target);
	}
	return answer;
    }

    //Erases all nodes containing a target value from the list
    circBag::size_type circBag::erase(const value_type& target)
    // Library facilities used: cstdlib, node1.h
    {
        size_type answer = 0;
        node *target_ptr;

        target_ptr = list_search(head_ptr, tail_ptr, target);
        while (target_ptr != NULL)
        {
            // Each time that target_ptr is not NULL, we have another occurrence
	    // of target. We remove this target using the same technique that
	    // was used in erase_one.
            target_ptr->set_data( head_ptr->data( ) );
            target_ptr = target_ptr->link( );
            target_ptr = list_search(target_ptr, tail_ptr, target);
            list_head_remove(head_ptr, tail_ptr);
	    --many_nodes;
            ++answer;
        }
        return answer;
    }

    //removes the node at the top of the list and sets tail_ptr to point to the new head_ptr
    void circBag::head_remove()
    {
        list_head_remove(head_ptr, tail_ptr);
        many_nodes--;
        return;
    }

    //inserts a node at the top of the list and sets tail_ptr to point to the new node.
    void circBag::insert(const value_type& entry)
    // Library facilities used: node1.h
    {
	list_head_insert(head_ptr, tail_ptr, entry);
	++many_nodes;
    }

    //deletes all nodes from the list
    void circBag::listClear()
    {
        list_clear(head_ptr, tail_ptr);
        many_nodes = 0;
    }

    //calls the list_length() toolkit function to return the number of nodes.
    size_t circBag::listLength()
    {
        return list_length(head_ptr, tail_ptr);
    }

    //prints the data from the linked-list
    void circBag::print()
    {
        node* cursor = head_ptr;

        do  {
            cout << cursor->data() << endl;
            cursor = cursor->link();
        } while (cursor != tail_ptr->link());
    }

}
