// FILE: cirBag.h
// CLASS PROVIDED: circBag
//
// TYPEDEFS for the circBag class:
//   circBag::value_type
//     is the data type of the items in the circBag. It may be any
//     of the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, a copy constructor, an assignment
//     operator, and a test for equality (x == y).
//
//   circBag::size_type
//     is the data type of any variable that keeps track of how many items are
//     in a circBag
//
// CONSTRUCTOR for the circBag class:
//   circBag( )
//     Postcondition: The circBag is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the circBag class:
//   size_type erase(const value_type& target)
//     Postcondition: All copies of target have been removed from the circBag.
//     The return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const value_type& target)
//     Postcondition: If target was in the circBag, then one copy of target has
//     been removed from the circBag; otherwise the circBag is unchanged. A true
//     return value indicates that one copy was removed; false indicates that
//     nothing was removed.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the circBag.
//
// CONSTANT MEMBER FUNCTIONS for the circBag class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the circBag.
//
//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the circBag.
//
// VALUE SEMANTICS for the circBag class:
//    Assignments and the copy constructor may be used with circBag objects.
//
// DYNAMIC MEMORY USAGE by the circBag:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, insert, operator +=, operator +, and the
//   assignment operator.

#ifndef MAIN_SAVITCH_BAG3_H
#define MAIN_SAVITCH_BAG3_H
#include <cstdlib>   // Provides size_t and NULL
#include "cNode.h"   // Provides node class
namespace main_savitch_5
{
    class circBag
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef node::value_type value_type;
        // CONSTRUCTORS and DESTRUCTOR
        circBag( );
        circBag(const circBag& source);
	~circBag( );
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);

        //remove the value at the top of the list
        void head_remove();

        //clear the list
        void listClear();

        //calls the list_length() function
        std::size_t listLength();

        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return many_nodes; }
        size_type count(const value_type& target) const;

        //OTHER FUNCTIONS
        void print();
    private:
        node *head_ptr; // List head pointer
        node *tail_ptr; // List tail pointer
        size_type many_nodes; // Number of nodes on the list
    };
}
#endif
