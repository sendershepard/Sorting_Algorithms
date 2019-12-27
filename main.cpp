//Sender Shepard
//Algorithms in C++
//
//Main program which will run both mergesort and quicksort.
//In this program the creation of an unordered array is performed through
//the creater_Array function. Thereafter, the sorting algorithms are 
//executed. The resulting array is then tested with the test function. 
//The number of operations for each algorithm are displayed. 
//
//For the sake of readibility the list is not displayed by default
//as the screen would be filled with numbers and making readibility
//practically impossible. 

#include "merge_sort.h"
#include "quick_sort.h"
#include <iostream>
#include <cmath>
#include <iostream>
using namespace std;

const int POWER_LENGTH = 19;
const int LENGTH = pow(2, POWER_LENGTH);

int test(int * array, int length);
int * create_array(int length);
void display_array(int * array, int arr_size);


int main()
{
    int array[] = {68, 76, 31, 99, 61, 21, 79, 20, 43, 4}; //create_array(LENGTH);
    int ops_count = 0; 
    int length = sizeof(array)/sizeof(array[0]);

/*
    cout << "\n\n\n| ***** Quicksort -:\n";
    //display_array(array, LENGTH);

    quick_sort(array, 0, LENGTH-1, ops_count);

    cout << "\nQuicksort applied to sort array in ascendent order:\n";
    //display_array(array, LENGTH);
    cout << "\n\n* Quicksort's number of assigning operations: " 
         << ops_count;
    cout << "\n* List is of size: " << LENGTH;
   
    if(test(array, LENGTH))
        cout << "\n\n| *** TEST PASSED- Array is sorted\n\n";
    else
        cout << "\n\n| *** FAIL- Fatal error. Array not sorted\n\n"; 
    
    array = create_array(LENGTH);
    ops_count = 0;

    cout << "Mergesort -: " << endl;
    //display_array(array, LENGTH);

    merge_sort(array, 0, LENGTH-1, ops_count);

    cout << "\n\n| ***** Mergesort to sort array in ascendent order:\n";
    //display_array(array, LENGTH);
    cout << "\n\n* Mergesort's number of assignment operations: " 
         << ops_count;
    cout << "\n* List is of size: " << LENGTH;

    if(test(array, LENGTH))
        cout << "\n\n| *** TEST PASSED - Array is sorted\n\n\n";
    else
        cout << "\n\n| *** FAIL - Fatal error. Array not sorted.\n\n\n"; 
*/ 
    //delete [] array;

    return 0;
}

//This function will return true if the array being passed to it as 
//an argument is in ascending order. Else it will return false. 
int test(int * array, int length)
{
    for(int i = 1; i < length; ++i)
    {
        if(array[i-1] > array[i])
            return 0;
    }

    return 1;
}

//This function creates an unordered array by flipping the bits to the 
//right by 1 for each instance of i. If these ints were to be represnted
//in bits, they would result in the Grey Binary Reflection numbers. 
int * create_array(int length)
{
    int * arr = new int[length];

    for(int i = 0; i < length; ++i)
        arr[i] = (i>>1)^i;

    return arr;
}

//Function to display an array. 
void display_array(int * arr, int arr_size)
{
    for(int i = 0; i < arr_size; ++i)
        cout << arr[i] << " - ";
}
