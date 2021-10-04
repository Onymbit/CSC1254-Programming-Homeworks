/*
        Author: W. Douglas Lafield
        OrderedList.h
*/
#ifndef _NODE_GUARD
#define _NODE_GUARD 1

using namespace std;

template <class T>
class Node
{
	public:
		T *value;
		struct Node *left;
		struct Node *right;

		Node(T *newValue) 
		{ 
		}
		
		~Node()
		{
		}
		
		bool insert(T *newItem, int (*defaultCompare)(T, T));
		/* If new item exists in tree, return false
		 * otherwise, add item to tree, and return true */
		 
		bool remove(T *target, int (*defaultCompare)(T, T));
		/* If target item exists in tree, remove it, and return true
		 * otherwise, return false */
		 
		T *search(T *target, int (*defaultCompare)(T, T));
		/* If target exists in tree, return pointer to the target
		 * otherwise, return null
		 * */
		 
		void traverse(void (*visit)(T));
		/* For each node, run the visit function */
		
		double traverseDouble(double initialValue, double (*visit)(double, T));
		/* for each node, run the visit function 
		 * The initial value is used as an arguement for the first 
		 * visit.  The return value for each visit is used as an 
		 * arguement for the next visit.  The return value for the 
		 * final visit is returned.
		 * */
		 
		int traverseInt(int initialValue, int (*visit)(int, T));
		/* for each node, run the visit function 
		 * The initial value is used as an arguement for the first 
		 * visit.  The return value for each visit is used as an 
		 * arguement for the next visit.  The return value for the 
		 * final visit is returned.
		 * */
		 
		void traverseOut(ofstream *f, void (*visit)(ofstream *, T));
		/* The file *f should already be open prior to calling traverseOut.
		 * 
		 * For each node, run the visit function
		 * */
};

/***************************************************/

template <class T>
T *Node<T>::search(T *target, int (*defaultCompare)(T, T))
{
} /* search */

/***************************************************/

template <class T>
bool Node<T>::insert(T *newItem, int (*defaultCompare)(T, T))
{	
} /* insert */

/***************************************************/

template <class T>
bool Node<T>::remove(T *target, int (*defaultCompare)(T, T))
{
} /* remove */

/***************************************************/

template <class T>
void Node<T>::traverse(void (*visit)(T))
{		
} /* traverse */

/***************************************************/

template <class T>
double Node<T>::traverseDouble(double initialValue, double (*visit)(double, T))
{	
} /* traverse double */

/***************************************************/

template <class T>
int Node<T>::traverseInt(int initialValue, int (*visit)(int, T))
{
} /* traverse int */

/***************************************************/

template <class T>
void Node<T>::traverseOut(ofstream *f, void (*visit)(ofstream *, T))
{
} /* traverse out */

/***************************************************/

#endif
