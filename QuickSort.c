
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defining size of the array to be sorted
#define MAX 100000

// function responsible for seperating the array to group of large numbers after the pivot
// and small numbers before the pivot 
int partition(int array[] , int l, int r)
{
    // setting the pivot to be the last element of the array
    int pivot = array[r] ;
    
    // temporary variable used for swapping
    int temp ;
    
    // initially make i point to the elemen before the first element
    int i = l-1 ;
     
    // iterate through the whole array from l to r-1 
    for (int j = l ; j <= r-1 ; j++)
    {
        // if the element's value less than the pivot
        if ( array[j] < pivot )
        {
            i++ ;                 // point to the next element in the array
            
            // swap element of i with element of j
            temp = array[i] ;
            array[i] = array[j] ;
            array[j] = temp ;
        }
    }
    
    // putting th pivot in the middle of the larger and smaller numbers
    // swapping with i+1 as last i is the last small number before the pivot
    temp = array[i+1] ;
    array[i+1] = array[r]  ;
    array[r] = temp ;
    
    // returning the place of the pivot
    return i+1 ;
}

// function responsible for the quick sort
// it takes the array the first & the last element of the array
void quicksort(int *array, int l, int r)
{
    // base case, if you reach that l is equal or greater than r quit the function
    if (l>=r)
    return ;
    
      // deviding the given array to smaller elements , pivot , larger elements
      int pivot = partition(array,l,r);
      
      // now the array is devided into 2 parts, recursivley quick sort these 2 parts
      quicksort(array,l,(pivot-1));
      quicksort(array,pivot+1,r);
}


// function to initiallize an array with random numbers
void init_mat(int *array , int n ){
        srand(time(NULL)) ;
	    for (int i = 0 ; i < n ; i++ )
	    {
	    int x = rand() ;
	    array[i] = x ;		
	    }
}

// function to print the array after sorting
void print_mat(int *array , int n)
{
    for(int i = 0 ; i<n ; i++)
    printf("%d \n", array[i]) ;
    
}


int main() {
    
    int x[MAX] ;             // declaring an array 
    init_mat(x,MAX);         // initiallizing an array with random numbers
    quicksort(x,0,MAX) ;     // Quick sort this array
    print_mat(x,MAX);        // print it out
    
    
      
    return 0;
}