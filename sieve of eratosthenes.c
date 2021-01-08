#include <stdio.h>
#include <math.h>
#include <stdbool.h> 

// definig the range to count the prime numbers in
#define N 100

// global array to be set of prime numbers
int arr[N] ;

// function to catch prime numbers in a certain range
void Catch_Prime (int *arr){
    
    // there 's no prime-even number except 2 
    // so setting an array with only odd values starting with 3
    // here we are assuming that all numbers are prime
    for (int i = 3 ; i < N ; i+=2)
    {
        arr[i] = i ;
    }
    
    // hard coding the first 3 elements of the array 
    arr[0] = 0 ;
    arr[1] = 0 ;
    arr[2] = 2 ;
    
    // this loop is responsible for replacing the multiples of the prime with 0 
    // 0 --> refers to not a prime number
    // output array of this loop will hold only prime numbers and the rest is 0
    for (int i = 2 ; i < N ; i++ )
    {
        for(int j = 2 ; (i*j) < N ; j++)
            arr[i*j] = 0 ;
    }
	
  }


int main (){
    
	 Catch_Prime(arr) ;
	 int Prime_counter = 0 ;
	
	    for (int i = 0 ; i < N ; i++)
	      {
	        if(arr[i])
	        {
		   // printing prime numbers in a range N	
	           printf("%d \n",i) ; 
	           Prime_counter ++ ;
	        }
	      }
	      // if you want to know how many prime number found from 0 to N	
	      printf("%d \n" ,Prime_counter) ;
    
}



