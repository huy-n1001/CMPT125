#include <stdlib.h>
#include "queue.h"

//  Creates a pointer to a new empty queue.  
//  Returns NULL on failure.
queue_t* queue_create(void)
{
	return LLcreate();
}
//  Recycles a queue.
void queue_destroy(queue_t * q)
{
	LLdestroy(q);
}
//  Returns 1 iff queue is empty.
int queue_isEmpty(queue_t * q)
{
	if ( q-> head == NULL)
		return 1;
	return 0;
}
//  Adds element to the back of the queue.
void queue_enqueue(queue_t * q, int element)
{
	LLappend(q, element);
}

//  Removes element from the front of the queue.  
//  Undetermined behaviour if queue is empty.
int queue_dequeue(queue_t * q)
{
	return LLremoveHead(q);
}
