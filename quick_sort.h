//Sender Shepard 
//Algorithms in C++
//
//Quick Sort
//
//"This file contains the Quick Sort Algorithm along with its helper
//functions: swap_ints, lomuto partitioning and hoare partitioning. The
//later will be utilized as the partitioning algorithm for the Quick 
//Sort Algorithm."
//Function to display an array. 
//
#include <iostream>
using namespace std;
void display_array(int * arr, int start, int end)
{
    for(int i = start; i < end + 1; ++i)
        cout << arr[i] << " - ";
}

//This function swaps two integers a and b of the same array
int swap_ints(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;

    return 3;
}

//Classic Lomuto paritioning. This function will partition the array
//by taking the first integer as a pivot to swap integers to the right
//if they are bigger than the pivot and to the left if they are smaller
//and finish by swaping the last swapped element
//with the pivot; thereafter, it returns the pivot position.
int lomuto(int * array, int start, int end, int & ops_count)
{
    int pivot = start; 
    int i = start + 1;

    for(int j = i; j < end; ++j)
    {
        if(array[j] < array[pivot])
        {
            swap_ints(array[i], array[j]);
            ++i;
        }
    }

    ops_count += swap_ints(array[pivot], array[i-1]);

    return (i-1);
}

//Hoare's Algorithm is an improved partitioning algorithm as it performs
//less swaps on average by scanning the array from both left and right
//simultaneously. This is the algorithm used to partition the table 
//in this project. In the end it returns the pivot position. 
int hoare(int * array, int start, int end, int & ops_count)
{
    int pivot = array[start]; //Choses the first element as the pivot
    int i = start - 1;
    int j = end + 1;
  
    cout << endl; display_array(array, start, end); cout << endl;

    //Loop swaps the elements into an ascending order 
    while(true)
    {
        //Scanning the array from left and right simultaneously
        do{
            ++i;
        }while(array[i] < pivot);

        do{
            --j;
        }while(array[j] > pivot);

        if(i >= j)
            return j; //Returns the index of the pivot

        ops_count += swap_ints(array[i], array[j]);
    }
}

//This is the Quick Sort algorithm. It takes the recursive approach
//by calling itself on and on each recurrence it paritions the array
//into sub arrays to be ordered both on the left of the pivot and the 
//right of the pivot. 
void quick_sort(int * array, int start, int end, int & ops_count)
{
    if(start < end)
    {   
        int pivot = hoare(array, start, end, ops_count); 
        cout<< "\np: " << pivot << " -> ";  cout << endl; display_array(array, start, end); cout << endl;

              
        quick_sort(array, start, pivot, ops_count);
        quick_sort(array, pivot + 1, end, ops_count);
    }
    
    return; 
}

