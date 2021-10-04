/*
        Author: W. Douglas Lafield
        Stack.h
*/
#ifndef _STACK_GUARD
#define _STACK_GUARD 1
#define STACK_MAX_NUM_OF_NODES 1000

using namespace std;

template <class T>
class Stack
{
	
	private:
		/* number of items currently in the Stack */
		int length; 	
		
		/* place where the Stack is stored */
		T nodes[STACK_MAX_NUM_OF_NODES];	
		
	public:
		/* constructer */
		Stack() { length = 0;  }
		
		/* destructer */
		~Stack() {}
		
		int getLength() { return length; }
		
		bool pop();
		/* remove item from the Stack and return the item */
		
		bool push(T item);
		/* add new item to the Stack */
		
		T *top();
		/* return item at top of the Stack without popping */
		
};

/***************************************************/

template <class T>
bool Stack<T>::pop()
{ /* remove item from the Stack and return the item */

	if(length == 0)
		return false;
		
	length--;
	return true;
	
} /* pop */

/***************************************************/

template <class T>
bool Stack<T>::push(T item)
{ /* add new item to the Stack */
	
	if(length + 1 == STACK_MAX_NUM_OF_NODES)
		return false;
		
	nodes[length] = item;
	length++;
	return true;
	
} /* push */

/***************************************************/

template <class T>
T *Stack<T>::top()
{ /* return item at top of the Stack without popping */
	
	return &(nodes[length - 1]);
	
} /* top */

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/

#endif
