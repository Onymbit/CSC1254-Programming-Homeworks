/*
        Author: W. Douglas Lafield
        OrderedList.h
*/
#ifndef _ORDERED_LIST_GUARD
#define _ORDERED_LIST_GUARD 1

using namespace std;

template <class T>
class OrderedList
{
	
	private:
		/* node structure */
		struct Node
		{
			T value;
			struct Node *nextNode;
		};
		
		/* pointer to the first node in the list */
		Node *firstNode;
	
		/* number of items currently in the list */
		int length; 	
		
		/* function that returns 1 if the left argument is greater 
		 * than the right argument, returns -1 if the right argument
		 * is greater than the left argument, and 0 otherwise */		
		int (*defaultCompare)(T, T);	
		
	public:
		/* constructer */
		OrderedList(int (*dc)(T, T))
		{ 
			length=0;
			defaultCompare=dc;
			firstNode=NULL;
		}
		
		/* destructer */
		~OrderedList() 
		{
			/* you must delete all nodes before deleting the ordered list */
			Node *temp;
			while(firstNode->nextNode==NULL){
				temp->nextNode=firstNode->nextNode;
				firstNode->nextNode=firstNode->nextNode->nextNode;
				delete temp->nextNode;
			}
		}
		
		int getLength();
		
		bool remove(T target);
		/* If target item exists in list, remove it, decrement length, and return true
		 * otherwise, return false */
	 
		bool insert(T newItem);
		/* If new item exists in list, or list is full, return false
		 * otherwise, add item to list, increment length, and return true */
	 
		T *search(T target);
		/* If target exists in list, return pointer to the target
		 * otherwise, return null
		 * */
		 
		void traverse(void (*visit)(int, T));
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
	return length;
} /* get length */

/***************************************************/

template <class T>
T *OrderedList<T>::search(T target)
{
	//check
	if(length==0)
		return NULL;
	Node *temp=firstNode;
	while(temp->nextNode!=NULL){
		if(compareStudentsByName(temp->value,target)==0){
			temp->value;
			return &temp->value;
		}
		temp=temp->nextNode;
			
	}
	if(compareStudentsByName(temp->value,target)==0)
		return &temp->value;
	return NULL;
	
} /* search */

/***************************************************/

template <class T>
bool OrderedList<T>::insert(T newItem)
{

	Node *newNode= new Node();
	newNode->value=newItem;
	newNode->nextNode=NULL;
	if(length==0){
		firstNode=newNode;
		length++;
		return true;
	}
	if(defaultCompare(firstNode->value,newItem)==1){
		newNode->nextNode=firstNode;
		firstNode=newNode;
		length++;
		return true;
	}
	Node *prev=firstNode;
	Node *after=prev->nextNode;
	while(after!=NULL&&defaultCompare(after->value,newItem)==-1){
		prev=prev->nextNode;
		after=after->nextNode;
	}
	if(after!=NULL&&defaultCompare(after->value,newItem)==0){
		return false;
	}
	newNode->nextNode=after;
	prev->nextNode=newNode;
	length++;
	return true;
} /* insert */

/***************************************************/

template <class T>
bool OrderedList<T>::remove(T target)
{
	if(length==0)
		return false;
	Node *temp=firstNode;
	Node *toRemove;
	if(compareStudentsByName(temp->value,target)==0){
		toRemove=temp;
		firstNode=temp->nextNode;
		temp->nextNode=temp->nextNode->nextNode;
		delete toRemove;
		return true;
	}
	Node *prev=firstNode;
	temp=temp->nextNode;
	while(temp!=NULL){
		if(compareStudentsByName(temp->value,target)==0){
			toRemove=temp;
			prev->nextNode=temp->nextNode;
			delete toRemove;
			return true;	
		}	
		temp=temp->nextNode;
		prev=prev->nextNode;
	}
	/*if(compareStudentsByName(temp->value,target)==0){
		toRemove=temp->nextNode;
		temp->nextNode=temp->nextNode->nextNode;
		delete toRemove;
		return true;	
	}*/

	return false;
} /* remove */

/***************************************************/

template <class T>
void OrderedList<T>::traverse(void (*visit)(int, T))
{
	Node *temp=firstNode;
	int i=0;
	while(temp!=NULL){
		visit(i,temp->value);
		i++;
		temp=temp->nextNode;
	}
} /* traverse */

/***************************************************/

template <class T>
double OrderedList<T>::traverseDouble(double initialValue, double (*visit)(double, T))
{
	Node *temp=firstNode;
	double tempDouble=initialValue;
	while(temp!=NULL){
		tempDouble=visit(tempDouble,temp->value);
		temp=temp->nextNode;
	}
	return tempDouble;
} /* traverse double */

/***************************************************/

template <class T>
int OrderedList<T>::traverseInt(int initialValue, int (*visit)(int, T))
{
	Node *temp=firstNode;
	int tempInt;
	while(temp!=NULL){
		tempInt=visit(initialValue,temp->value);
		temp=temp->nextNode;
	}
	return tempInt;
} /* traverse double */

/***************************************************/

template <class T>
void OrderedList<T>::traverseOut(ofstream *f, void (*visit)(ofstream *, T))
{
	Node *temp=firstNode;
	while(temp!=NULL){
		visit(f,temp->value);
		temp=temp->nextNode;
	}
}

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/

#endif
