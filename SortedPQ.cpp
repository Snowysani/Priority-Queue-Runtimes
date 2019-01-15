//
//  SortedPQ.cpp
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
class SortedPQ
{
private:
    node<Type> *head;
    int count;
    
public:
    
    SortedPQ() { // constructor
        head = NULL; // set the head to NULL to start off
        count = 0; // get a count for the size
    }
    
    ~SortedPQ(){ // build the destructor
        cout << "Sorted PQ Destructor called."<< endl;
    }
    
    bool isEmpty() {
        if (head == NULL) // if there are no elements
            return true;
        else
            return false;
    }
    
    int size(){ // size function
        return count; // return the count we setup earlier
    }
    
    void insertItem(Type item) { //Insert function
        node<Type> *temp; // start with the temp node
        temp = new node<Type>; // temp
        temp->data = item; // set the data equal to what you're inserting
        temp->priority = item; // set the priority to the prio key, which is the item
        
        if (head == NULL || item < head->priority){ // if head is null or the head's prio key is greater than the insert
            // This means you can just throw it at the front, there's no items or it's inserting a min already 
            //can do it like this because the item itself is the priority key
            temp->next = head;
            head = temp;
            count++;
        }
        else // Otherwise, assume the item needs to be put in the middle of the list somewhere
        {
            node<Type> *walker; // setup a temp node
            walker = head; // set it equal to the head
            while (walker->next != NULL && walker->next->priority <= item)
                walker=walker->next; // have the walker go down until it finds its spot in the list
            temp->next = walker->next;
            walker->next = temp;
            count++; // add one to the size count. 
        }
    }

    Type removeMin() {
        node<Type> *temp; // setup the temp variables
        Type min;
        if (isEmpty()){
            throw EmptyStackException();
        }
        else
        {
            temp = head; // temp = head
//            cout<<"Removing Min: "<<temp->data<<endl;
            min = temp->data; // set the min return variable to the data
            temp = temp->next; // Go forward one in the temp
            head = temp; // ** Pretty much doing head = head->next
            delete temp; // delete the temp
            count--; // Remove one from my count variable
        }
        return min;
    }
    
    Type minValue() { // Here you want to return the min
        Type min = 0;
        if (isEmpty()){ // Check to be sure it has elements in it
            throw EmptyStackException(); // If not, throw an exception out there
        }
        else // otherwise it's got stuff in it. cool.
            min = head->data; // Else you want to return the data
        return min; // return the min
        // Was getting compiler errors here on Xcode until I made min its own variable 
    }
    
    void printQueue() // Go and print it, unless it's empty, then throw out an except.
    {
        node<Type> *temp;
        temp = head;
        if (isEmpty()){
            throw EmptyStackException();
        }
        else
        {
            cout<<"Sorted PQ:" << endl;
            while(temp != NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
    }
};
