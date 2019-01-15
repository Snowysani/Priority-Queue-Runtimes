//
//  UnsortedPQ.cpp
//  Gallegos_Michael_PA3
//
//  Created by Michael Gallegos on 10/22/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//

#include <stdio.h>
#include "PriorityQueue.h"
#include <iostream>
using namespace std;

template<class Type>
class UnsortedPQ
{
private:
    node<Type> *head;
    int count;
public:
    
    UnsortedPQ() { // constructor
        head = NULL; // set the head to NULL to start off
        count = 0; // get a count for the size
    }
    
    ~UnsortedPQ(){ // build the destructor
        cout << "Unsorted PQ Destructor called."<< endl;
    }
    
    bool isEmpty() {
        if (head == NULL) // if there are no elements
            return true;
        else
            return false;
    }
    
    int size(){ // size function
        return count; // return the count we setup earlier
        // I should probably change this for Unsorted, and find the size manually. 
    }
    
    void insertItem(Type item) { //Insert function
        node<Type> *temp; // start with the temp node
        temp = new node<Type>; // temp
        temp->data = item; // set the data equal to what you're inserting
        temp->priority = item; // set the priority to the prio key, which is the item
        temp->next = head;
        head = temp; // head is now set to temp
        count++; // Insert function ends by adding one to the count
    }
    
    Type removeMin() {
        Type min = minValue(); // Get the minimum from the other function
        struct node<Type> *temp = head; // Start the temp node
 //       temp = head;// make this walk along the list until you reach the min
        while (temp->next->data != min) // Go until the next node's data is the min
            temp->next = temp->next->next; // Switch it
        temp->next = temp->next->next; // Make the pointers have the jump, removing the min
        delete temp; // delete the node
        count--; // Take one out of the length/size
        return min;// return the min as well as remove it
    }
    
    Type minValue() {
        Type min; // setup the temp variables
        struct node<Type> *temp;
        temp = head;
        // Now you want to find the smallest element in the list, since it's unsorted 
        if (isEmpty())
            throw EmptyStackException();
        else {
            while (temp != NULL) { // Go while it's not null, go down the list
                // If min is greater then head->data then
                // assign value of head->data to min
                // otherwise node point to next node.
                if (min > temp->data) // Switch if it's a smaller value
                    min = temp->data;
                temp = temp->next; // Move the pointer in the while loop
            }
        }
        delete temp;
        return min; // return the min value
    }
    
    void printQueue()
    {
        node<Type> *temp;
        temp = head;
        if (isEmpty())
            throw EmptyStackException();
        else
        {
            cout<<"Unsorted PQ:" << endl;
            while(temp != NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
    }
};
