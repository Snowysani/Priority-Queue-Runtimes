#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <exception>
#include <iostream>
using namespace std;

class EmptyStackException: public std::runtime_error{
    // Create a class for empty stack exception for later
public:
    EmptyStackException() : runtime_error("Empty Stack Exception"){}
};

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */
template<class Type>
struct node
{
    Type priority; // Set up a priority key. This is for sorted and unsorted.
    // I understand this isn't totally necessary,
    //  but it makes sense to me with how I setup my insert function.
    Type data; // the data value
    struct node *next; // the next pointer
};

template <class Type>
class PriorityQueue
{
private:
	// data here

public:
   PriorityQueue(void);

   ~PriorityQueue(void);

   bool isEmpty(void);

   int size(void);

   // inserts a piece of data into the priority queue
   void insertItem ( Type data );

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void );

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void );
};

#endif
