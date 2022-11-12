// FILE: cNode.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "cNode.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>
using namespace std;

namespace main_savitch_5
{
    //modified so that it uses a do while loop to count the number of nodes.
    size_t list_length(node* head_ptr, node* tail_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	cursor = head_ptr;

	do  {
            answer++;
            cursor = cursor->link();
        } while (cursor != tail_ptr->link());

	return answer;
    }

    //modified so that it sets tail_ptr->link() to point to the new node entry
    void list_head_insert(node*& head_ptr, node*& tail_ptr, const node::value_type& entry)
    {
        head_ptr = new node(entry, head_ptr);

       if (head_ptr->link() == NULL)
        {
           tail_ptr = head_ptr;
        }
       else
            tail_ptr->set_link(head_ptr);
    }



    //modified so that it uses a do while loop that stops when cursor points to tail_ptr->link()
    node* list_search(node* head_ptr, node *tail_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	node *cursor = head_ptr;

	do  {
            if (target == cursor->data( ))
                return cursor;
            else
                cursor = cursor->link();
        } while (cursor != tail_ptr->link());
        return NULL;
    }

    //modified so that it uses a do while loop that stops when cursor points to tail_ptr->link()
    const node* list_search(const node* head_ptr, const node *tail_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	const node *cursor = head_ptr;

	do  {
            if (target == cursor->data( ))
                return cursor;
            else
                cursor = cursor->link();
        } while (cursor != tail_ptr->link());
        return NULL;
    }


    //modified so that tail_ptr->link() points to the new head_ptr after removing the old head_ptr
    void list_head_remove(node*& head_ptr, node*& tail_ptr)
    {
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link();
	tail_ptr->set_link(head_ptr);
	delete remove_ptr;

    }

    //clears the entire linked-list
    void list_clear(node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {

	    do {
            list_head_remove(head_ptr, tail_ptr);
	    } while (head_ptr != tail_ptr);

        //delete head_ptr;
        delete tail_ptr;
        //tail_ptr->set_data(NULL);
        //tail_ptr->set_link(NULL);
    }

    /*
    void list_insert(node* previous_ptr, node *tail_ptr,
                     const node::value_type& entry)
    {
	node *insert_ptr;

	if (previous_ptr == tail_ptr)
    {
        insert_ptr = new node(entry, tail_ptr->link());
        tail_ptr = insert_ptr;
    }
    else
        insert_ptr = new node(entry, previous_ptr->link( ));
        previous_ptr->set_link(insert_ptr);
    }

    void list_remove(node* previous_ptr, node*& head_ptr, node*& tail_ptr)
    {
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );

	if (previous_ptr->link() == tail_ptr)
    {
        tail_ptr = previous_ptr;
        tail_ptr->set_link(head_ptr);
    }

    previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
    }
    */


}
