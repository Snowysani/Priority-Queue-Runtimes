//
//  main.cpp
//  Gallegos_Michael_PA3
//
//  Created by Michael Gallegos on 10/22/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//
/*
 For this programming assignment, you will implement a Priority Queue.
 Your Priority Queue can grow dynamically as in the Stack assignment
    (although you should use a method with amortized cost O(1) for insertion)
    or you may make a Priority Queue large enough to fit all of your data ahead of time.
 You will build three different implementations of the Priority Queue.
 Two of these implementations will be based on a List.
 The first list implementation, UnsortedPQ, should use an unsorted list to store the data.
 The second list implementation, SortedPQ, should use a sorted list.
 The third implementation, HeapPQ, should be an array-based implementation of a Heap.
 
 We will test your implementations using a set of numbers in a text file named “numbers.txt”.
 Each line of the file will contain a number.
 The first number will be which Priority Queue to use (0=UnsortedPQ, 1=SortedPQ, 2=HeapPQ).
 The second number will be the number of remaining elements in the file, n.
 The first two numbers of the file (queue type and n) will NOT be inserted into your Priority Queue.
 However, the remaining n numbers will be inserted.  You should then remove all n numbers and print them to the screen.
 Here is an example numbers.txt file.
 
 Using your three implementations, you will also time how long it takes to
    insert n random numbers and the total time to insert n random numbers and remove n random numbers.
 You may use a random number generating as opposed to the file input above.
 Time how long insertion takes using the StopWatch class we provided.
 You should measure the total time at fixed intervals.
 You will then show a graph of the total insertion time versus the number of items inserted for each implementation.
 You will then time how long insertion and removal takes by inserting n numbers and removing n numbers for each implementation.
 You will then graph the sorting time versus the number of elements.
 This process will allow you to see how your choice of implementation can affect performance.
 */

#include <iostream>
#include "Timer.h"
#include "PriorityQueue.h"
#include "UnsortedPQ.cpp"
#include "SortedPQ.cpp"
#include "HeapPQ.cpp"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void printVector(vector<int> const &inputVector){  // Learned this from techiedelight.com
    for (int i = 0; i < inputVector.size(); i++){
        cout << inputVector.at(i) << endl;
    }
}

int main(int argc, const char * argv[]) {
    // First setup your input vector. The first element is going to be the type, the second is going to be the number of elements.
    // The rest on is your values.
    // For the sake of demonstration, I will use long ints.
   
    // I used the below to generate the list of numbers to sort
    // ofstream ofs("/Users/Snowspeeder/Documents/School/CSCE 221/PA3/Gallegos_Michael_PA3/Gallegos_Michael_PA3/numbers copy.txt");
//        for (long int i = 0; i < 100000; i++)
//            ofs << rand() % 500 + 1 << endl;
//        ofs.close();

//    string nameOfFile;
//    cout << "Please input the path for your file. : ";
//    cin >> nameOfFile;
//    cout << endl;
//    string line;
//    vector<int> inputVector;
//    ifstream myfileinput("/Users/Snowspeeder/Documents/School/CSCE 221/PA3/Gallegos_Michael_PA3/Gallegos_Michael_PA3/numbers copy.txt");
////    string nameOfFile;
////    cout << "Please input the file path: ";
////    cin >> nameOfFile;
////    cout << endl;
////    ifstream myfileinput(nameOfFile);
//
//    while(getline(myfileinput,line)){ // Make each vector element a line from the file
//        inputVector.push_back (stoi(line));
//    }
//    myfileinput.close(); // close the file
//    printVector(inputVector);
//
//    cout << "The list you inputted has " << inputVector.size() << " elements that will be sorted." << endl;
//    // Now setup the different usage cases
//
//    if (inputVector[0] == 0){ // If the first element is 0
//        // Do UnsortedPQ
//            UnsortedPQ <long int> q1;
//            CStopWatch j; // Start the timer
//            for (long int i = 2; i < inputVector[1]; i++) // Do the inserts based on the size.
//            {
//                q1.insertItem(inputVector[i]);
//            }
//        cout << "Time taken for Unsorted insert: " << j.GetElapsedSeconds();
//        cout << " seconds." << endl;
//        cout << "Min: " << q1.minValue() << endl;
//        j.Reset();
//        long int i = 0;
//        while(i < inputVector[i]){
//            q1.removeMin();
//            i++;
//        }
////        j.Reset(); // This resets the timer
////        for (long int i = 3; i < inputVector[1]; i++) // This removes all of the mins
////        {
////            q1.removeMin();
////        }
//        cout << "Time taken for Unsorted Remove Min: " << j.GetElapsedSeconds();
//        cout << " seconds." << endl;
////            q1.printQueue();
//    }
//    else if (inputVector[0] == 1){ // If the first element is 1
//        // Do SortedPQ
//        SortedPQ <long int> q2;
//        CStopWatch j;
//        for (long int i = 3; i <= inputVector[1]; i++)
//        {
//            q2.insertItem(inputVector[i]);
//        }
//        cout << "Time taken for Sorted insert: " << j.GetElapsedSeconds();
//        cout << " seconds." << endl;
//        cout << "Min: " << q2.minValue() << endl;
//        j.Reset();
//        long int i = 0;
//        while(i < inputVector[i]){
//            q2.removeMin();
//            i++;
//        }
//        //        j.Reset(); // This resets the timer
//        //        for (long int i = 3; i < inputVector[1]; i++) // This removes all of the mins
//        //        {
//        //            q1.removeMin();
//        //        }
//        cout << "Time taken for Sorted Remove Min: " << j.GetElapsedSeconds();
//        cout << " seconds." << endl;
//        //q2.removeMin();
//        //q2.printQueue();
//    }
//    else if (inputVector[0] == 2){ // If the first element is 2, use heap
//        // Do HeapPQ
//        HeapPQ <long int> h(inputVector[1]);
//        cout << "Starting stopwatch for insert function." << endl;
//        CStopWatch j;
//        for (long int i = 3; i <= inputVector[1]; i++){ // Go as long as there's still elements in the list
//            // Can do it this way since you're always given how many elements remaining there are in the list
//            h.insertItem(inputVector[i]);
//        }
//        cout << "Time taken for Heap PQ insert: " << j.GetElapsedSeconds();
//        cout << " seconds." << endl;
//        cout << "Min value: " << h.minValue() << endl;
////        cout << "Removing min: " << h.removeMin() << endl;
////        cout << "New Min value: " << h.minValue() << endl;
//        j.Reset();
//        long int i = 0;
//        while(i < inputVector[i]){
//            h.removeMin();
//            i++;
//        }
//        //        j.Reset(); // This resets the timer
//        //        for (long int i = 3; i < inputVector[1]; i++) // This removes all of the mins
//        //        {
//        //            q1.removeMin();
//        //        }
//        cout << "Time taken for Heap Remove Min: " << j.GetElapsedSeconds();
//        cout << " seconds." << endl;
//    }
//    else
//        throw EmptyStackException();
    
    int k = 2;
    int arr[] = {1,2,3};
    vector<int> inputVector;
    for (int i = 0; i < 3; i++){ // i < size of array
        inputVector.push_back(arr[i]);
    }
    HeapPQ <int> h(inputVector.size());
    for (int i = 0; i <= inputVector.size(); i++){
        // Go as long as there's still elements in the list
        h.insertItem(inputVector[i]);
    } // So now you have your min heap. Now go ahead and do it until you get the kth largest element, at the back.
    int i = 0;
    cout << "Min value: " << h.minValue() << endl;
    while (i < inputVector.size() - k) { // Go until size-k
        h.removeMin(); // This is described in my other function
        i++;
    }
    cout << "Kth largest value: " << h.minValue() << endl;

//     int i = 0;
//    while(i < inputVector.size()){
//        h.removeMin();
//        i++;
//    }
    //std::cout << "Hello, World!\n";
    return 0;
}
