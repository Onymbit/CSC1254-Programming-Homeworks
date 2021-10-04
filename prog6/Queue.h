/*
        Author: W. Douglas Lafield and Jameson Connor Harrington
        Queue.h
*/
#ifndef _QUEUE_GUARD
#define _QUEUE_GUARD 1
#define QUEUE_MAX_NUM_OF_NODES 1000

using namespace std;

template <class T>
class Queue
{
	
	private:
		/* number of items currently in the queue */
		int length,first,last;
		T array[QUEUE_MAX_NUM_OF_NODES]; 	
		
		/* You put the rest of the private variables here */
		
	public:
		/* constructer */
		Queue(){
			length=first=last=0;
		}
		
		/* destructer */
		~Queue() 
		{}
		
		int getLength() { return length; }

		bool dequeue();
		/* remove item from the front of the queue and return the item */
		
		bool enqueue(T item);
		/* add new item to the end of the queue */
		
		T *front();
		/* return item at front of the queue without dequeueing */
		
};


/***************************************************/

template <class T>
bool Queue<T>::dequeue()
{ /* remove item from the front of the queue and return the item */
	if(length==0)
		return false;
	if(length==1){
		length=first=last=0;
		return true;
	}
	length--;
	first=(first+1)%QUEUE_MAX_NUM_OF_NODES;
	return true;
} /* dequeue */

/***************************************************/

template <class T>
bool Queue<T>::enqueue(T item)
{ /* add new item to the end of the queue */
	if(length==QUEUE_MAX_NUM_OF_NODES)
		return false;
	if(length==0){
		array[0]=item;
	}
	last=(last+1)%QUEUE_MAX_NUM_OF_NODES;
	array[last]=item;
	length++;
	return true;
} /* enqueue */

/***************************************************/

template <class T>
T *Queue<T>::front()
{ /* return item at front of the queue without dequeueing */
	if(length==0)
		return NULL;
	return &array[first];
} /* front */

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/

#endif
