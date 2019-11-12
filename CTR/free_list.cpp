/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <iostream>
#include "free_list.hpp"

/*--------------------------------------------------------------------------*/
/* NAME SPACES */
/*--------------------------------------------------------------------------*/

using namespace std;
/* I know, it's a bad habit, but this is a tiny program anyway... */

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
//String to hold empty space list
	string emptyList;

SegmentHeader::SegmentHeader(size_t _length, bool _is_free) {
  length = _length;
  is_free = _is_free;
  cookie = COOKIE_VALUE;
  emptyList = "";
}

SegmentHeader::~SegmentHeader() {
  int i = 0;
  while( i < total_blocks){
  	allocation_array[i] = 0;
  	i++;
  }
}


void SegmentHeader::CheckValid() {
  if (cookie != COOKIE_VALUE) {
    cout << "INVALID SEGMENT HEADER!!" << endl;
    //assert(false);
    // You will need to check with the debugger to see how we got into this
    // predicament.
  }
}

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR CLASS FreeList */
/*--------------------------------------------------------------------------*/

//Generate a freelist according to the allocated and unallocated memory spaces
FreeList::FreeList() {
	emptyList = "";
	int i = 0;
  while( i < total_blocks){
  	if(allocation_array[i] == 0){
  		emptyList+=i+",";
	  }
	  i++;
  }
}

//unallocate the allocated memory before exiting the program
FreeList::~FreeList() {
  //free(total_storage);
  emptyList = "";
}

//bool FreeList::Add(SegmentHeader * _segment) {
//  assert(false); // This implementation does nothing, other than abort.
//}

//bool FreeList::Remove(SegmentHeader * _segment) {
//  assert(false); // This implementation does nothing, other than abort.
//}
