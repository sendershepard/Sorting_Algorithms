//Sender Shepard 
//Algorithms in C++
//
//Merge Sort
//
//"This file contains the algorithm for merge sort along with 
//    it's helper functions: copy_array and merge"

//Provides an additional copy of the original array
int * copy_array(int * array, int start, int end)
{
    int * copy = new int[end]; //Dynamically allocating an array of ints

    //For loop to copy each element of the received array
    for(int i = 0; i < end; ++i)
        copy[i] = array[start+i];

    return copy; //Returns the pointer of the newly created array
}

//The merge function merges two arrays into one. This is accomplished
//by first copying array a and array b into new lists which will then 
//be placed into the original array in a sorted fashion.
void merge(int * array, int start, int middle, int end, int & ops_count)
{
    //Creating array a to copy the contents of the original array
    int arr1_length = ((middle-start)+1); 
    int * arr1 = copy_array(array, start, arr1_length);

    //Creating array b to copy the contents of the original array
    int arr2_length = (end-middle);
    int * arr2 = copy_array(array, middle+1, arr2_length);
    //Variables to track the index of the arrays
    int i = 0, k = 0, j = 0;

    //Placing elements of a & b into the original array in ascending order
    while(k < arr1_length && j < arr2_length)
    {
        if(arr1[k] <= arr2[j])
        {
            array[start] = arr1[k];
            ++k;
            ++ops_count;
        }
        else
        {
            array[start] = arr2[j];
            ++j;
            ++ops_count;
        }
        ++start;
    }

    //Loops that account for the case when sub-array lenght is not equal
    while(k < arr1_length)
    {
        array[start] = arr1[k];
        ++k;
        ++start;
        ++ops_count;
    }

    while(j < arr2_length)
    {
        array[start] = arr2[j];
        ++j;
        ++start;
        ++ops_count;
    }

    //Deleting the memory of the dynamically allocated arrays
    delete [] arr1; 
    delete [] arr2;

    return;
}

//Merge sort using the divide-and-conquer strategy of diving the 
//array into sub-arrays of N/2 through a series of recursive calls
//until sub-arrays of one element are achieved
void merge_sort(int * arr, int start, int end, int & ops_count)
{
    //Execute until the sub-array is no smaller than one element
    if(start < end)
    {
        int mid = (start + (end-1)) / 2; //Defines current array

        merge_sort(arr, start, mid, ops_count); //Sort the first part
        merge_sort(arr, mid+1, end, ops_count); //Sort hte second part 

        merge(arr, start, mid, end, ops_count); //Serge both parts arrays
    }

    return;
}

