/*
        Author: W. Douglas Lafield
        OrderedList.h
*/
#ifndef _ORDERED_LIST_GUARD
#define _ORDERED_LIST_GUARD 1

#include "Node.h"

using namespace std;

template <class T>
class OrderedList
{
	
	private:
		
		/* pointer to the first node in the list */
		Node<T> *root;
	
		/* number of items currently in the list */
		int sizeOfTree; 	
		
		/* function that returns 1 if the left argument is greater 
		 * than the right argument, returns -1 if the right argument
		 * is greater than the left argument, and 0 otherwise */		
		int (*defaultCompare)(T, T);	
		
	public:
		/* constructer */
		OrderedList(int (*dc)(T, T))
		{ 
			defaultCompare=dc;
			sizeOfTree=0;
			root=new Node<T>(NULL);
		}
		
		/* destructer */
		~OrderedList() 
		{
			/*if(root!=NULL){
		        delete left;
		        delete right;
		        delete(root);
		        if(root->left!=NULL)
		            root->left=NULL;
		        if(root->right!=NULL)
		            root->right=NULL;
		        root=NULL;
			}*/
		}
		
		int getLength();
		
		bool remove(T *target);
		/* If target item exists in tree, remove it, decrement size, and return true
		 * otherwise, return false */
	 
		bool insert(T *newItem);
		/* If new item exists in tree, return false
		 * otherwise, add item to tree, increment length, and return true */
	 
		T *search(T *target);
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
int OrderedList<T>::getLength() 
{ 
	return sizeOfTree;
} /* get length */

/***************************************************/

template <class T>
T *OrderedList<T>::search(T *target)
{
	return root->search(target,defaultCompare);
} /* search */

/***************************************************/

template <class T>
bool OrderedList<T>::insert(T *newItem)
{
	if(root->insert(newItem,defaultCompare)){
		sizeOfTree++;
		return true;
	}
	return false;
	
} /* insert */

/***************************************************/

template <class T>
bool OrderedList<T>::remove(T *target)
{
	return root->search(target,defaultCompare);
} /* delete */

/***************************************************/

template <class T>
void OrderedList<T>::traverse(void (*visit)(T))
{
	root->traverse(visit);
} /* traverse */

/***************************************************/
template <class T>
double OrderedList<T>::traverseDouble(double initialValue, double (*visit)(double, T))
{
	return root->traverseDouble(0,visit);
} /* traverse double */

/***************************************************/

template <class T>
int OrderedList<T>::traverseInt(int initialValue, int (*visit)(int, T))
{
	return root->traverseInt(0,visit);
} /* traverse int */

/***************************************************/

template <class T>
void OrderedList<T>::traverseOut(ofstream *f, void (*visit)(ofstream *, T))
{
	root->traverseOut(f,visit);
} /* traverse for the purpose of outputing to the file */

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/

#endif
