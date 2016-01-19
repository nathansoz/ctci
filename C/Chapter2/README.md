Chapter 2
=========

This chapter uses the single and double linked list implementations in /C/DataStructures/ called linked_list_s and 
linked_list_d. These linked list implementations are generic in that the nodes hold void* as data. I have implemented
functions for manipulating linked lists that can do the following:

* initialization and destruction
* adding and removing elements from the head, tail, and at a specified location
* getting elements from the head, tail, and at a specified location

Some of these functions aren't traditional for a linked list (inserting at, for example). Traversal of the linked list
is abstracted away from the consumer of the library, making it function more like a vector in the C++ STL. However,
the implementation keeps the advantages of using a linked-list backed collection (constant insert/remove at head or head/tail,
linear traversal, etc).

Finally, in implementing the library, I inadvertently solved some of the chapter's problems. If a problem is trivially solved
by my library, I note so during the problem description and in the source code.

#2-1
Problem 2-1 asks the programmer to write code that removes duplicates from a linked list. An optional requirement is to 
do so in-place, without allocating extra memory.

The function ll_remove_duplicates takes a linked list and a function pointer to test equality. 
It does so "in-place", allocating no extra memory.

#2-2
Problem 2-2 asks the programmer to write code that returns the kth index from the tail element of a linked list.
My linked list interface makes this trivial to do, as you simply take the size and subtract k from it (and subtract
1 to make it 0-indexed). The algorithm then just does a call to lls_get_at, which iterates from head to (size - k - 1)
in linear time.