//
//  HeapPQ.cpp
//  Gallegos_Michael_PA3
//
//  Created by Michael Gallegos on 10/22/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//

#include <stdio.h>
#include "PriorityQueue.h"
using namespace std;

template<class Type>
void swap(Type *x, Type *y) // This comes in handy when dealing with the array insert/remove functions
{
    Type temp = *x;
    *x = *y;
    *y = temp;
}

template <class Type>
class HeapPQ
{
    Type *arr; // pointer to array of elements in heap
    Type capacity; // maximum possible size of min heap
    Type heap_size; // Current number of elements in min heap
public:
    // Constructor
    HeapPQ(Type cap){
        heap_size = 0;
        capacity = cap;
        arr = new Type[cap];
    }
    
    ~HeapPQ(){
        cout << "Destructor called for Heap PQ" << endl;
    }
    
    bool isEmpty(){ // check if the array is empty
        if (size() == 0)
            return true;
        else
            return false;
    }
    
    Type size(){ // return the size
        return heap_size;
    }
    
    // Inserts a new key 'k'
    void insertItem(Type k)
    {
        // With the way the test cases will be given, you always know how big to make your array.
        // First insert the new key at the end
        heap_size++;
        Type i = heap_size - 1;
        arr[i] = k;
        
        // Do this to be sure it's a min heap
        // While loop that swaps two parts just in case!
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }
    
    // This removes the root and moves the array to min heap 
    Type removeMin()
    {
        if (heap_size <= 0)
            throw EmptyStackException();
        if (heap_size == 1)
        {
            heap_size--;
            return arr[0];
        }
        
        // Get the min and drop it out of the heap
        Type root = arr[0];
        arr[0] = arr[heap_size-1];
        heap_size--;
        Upheap(0);
        
        return root;
    }
    
    // Return the root, the min at the time
    Type minValue() {
        return arr[0];
    }
    
    // Get the parent
    Type parent(Type i) {
        return (i-1)/2;
    }
    
    // Get the left kid
    Type left(Type i) {
        return (2*i + 1);
    }
    
    // Get the right kid
    Type right(Type i) {
        return (2*i + 2);
    }
    
    //
    void Upheap(Type i) // Learned this from the lecture slides and online binary heap articles
    {
        Type l = left(i); // setup your kid variables
        Type r = right(i);
        Type smallest = i; // Your input is always gonna be the 0 to start
        if (l < heap_size && arr[l] < arr[i]) // If the left is elss than the size, and left is less than what you're looking at
            smallest = l; // set the smallest equal to the left
        if (r < heap_size && arr[r] < arr[smallest]) // Do the same with the right, if the right is less than the smallest
            smallest = r; // set the smallest one equal to the r
        if (smallest != i) // as long as the smallest one is not the iteration
        {
            swap(&arr[i], &arr[smallest]); // switch them out and do it again
            Upheap(smallest); // Do it again ^^
        }
    }
    void Downheap(int n)
    {
        int i = minValue();
        int largest = minValue(); // Input the root
        int l = 2*i + 1; // left = 2*i + 1
        int r = 2*i + 2; // right = 2*i + 2
        
        // If the left kid turns out to be greater than the root, the largest is now the root
        if (l < n && arr[l] > arr[largest])
            largest = l;
        
        // If the right kid is larger than everything checked up to this point
        if (r < n && arr[r] > arr[largest])
            largest = r;
        
        // Now you can do a check to be sure the largest isn't the input
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            
            // Now go ahead and do it again
            Downheap(n);
        }
    }
   // Read this from geeks for geeks
    void MaxHeapSort(int n)
    {
        // Now you can rearrange the heap
        for (int i = n / 2 - 1; i >= 0; i--)
            Downheap(n);
        
        // Go through the heap one by one
        for (int i = 0; i< n-1; i++)
        {
            // Move current root to end
            swap(arr[0], arr[i]);
            
            // Heap downwards at this node
            Downheap(i);
        }
    }
};
