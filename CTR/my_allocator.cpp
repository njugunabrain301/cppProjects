/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <cstdlib>
#include "my_allocator.hpp"
#include <assert.h>
#include <iostream>

/*--------------------------------------------------------------------------*/
/* NAME SPACES */
/*--------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------*/
/* GLOBAL VARIABLES */
/*--------------------------------------------------------------------------*/

//holds the list of allocated memory spaces
    int *allocation_array;
//holds actual address of the memory
    int *allocated_space;
//total amount of storage given
    int total_storage;
//total number of available blocks
	int total_blocks;
//size of one block
	int unit_size;

//Initializer for the my allocater class.
//Initialize all global variables
MyAllocator::MyAllocator(size_t _basic_block_size, size_t _size) {

  unit_size = _basic_block_size;
  total_storage = _size;

  total_blocks = (int) (_size/_basic_block_size);
  int i = 0;

  while(i < total_blocks){
  	allocation_array[i] = 0;
  	i++;
  }
}

//unallocate the allocated memory before exiting the program
MyAllocator::~MyAllocator() {
  free(allocated_space);
}

//Allocate a space and return the address of the space
Addr MyAllocator::Malloc(size_t _length) {
  int found = 0;
  int beginIndex = -1;
  int series = 0;
  int fibo = 1;
  int prevFibo = 1;
  int i = 0;
  //Get enough space to allocate to the request
  while( i <total_blocks){
  	int buff = fibo;
  	fibo= prevFibo+fibo;
  	prevFibo = buff;
  	if(allocation_array[i] == 0){
  		series++;
  		found += unit_size;
  		if(beginIndex == -1){
  			beginIndex = i;
		  }
  		if(found >= _length){
  			break;
		  }
	  }else{
	  	found = 0;
	  	beginIndex = -1;
	  	series = 0;
	  }
	  i++;
  }
  //Check if sufficient space was found
  if(beginIndex >= 0){
  	for(int i = beginIndex; i < series; i++){
  		allocation_array[i] = 1;
	  }
  }else{
  	cout << "Insufficient memory";
  }

  return malloc(_length);
}

//Function to keep track of the freed spaces and update the allocation array
bool MyAllocator::Free(Addr _a) {
  int i = 0;
  while(i < total_blocks){
  	if(_a == malloc(allocation_array[i])){
  		allocation_array[i] = 0;
  		return true;
	  }
	  i++;
  }
  return false;
}

