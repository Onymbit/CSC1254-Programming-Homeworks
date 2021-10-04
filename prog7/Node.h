/*
        Author: W. Douglas Lafield
        OrderedList.h
*/
#ifndef _NODE_GUARD
#define _NODE_GUARD 1

using namespace std;
/*
Program received signal SIGABRT, Aborted.
__GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:50
50      ../sysdeps/unix/sysv/linux/raise.c: No such file or directory.
(gdb) backtrace
#0  __GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:50
#1  0x00007ffff7afa535 in __GI_abort () at abort.c:79
#2  0x00007ffff7ec2983 in ?? () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#3  0x00007ffff7ec88c6 in ?? () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#4  0x00007ffff7ec8901 in std::terminate() () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#5  0x00007ffff7ec8b34 in __cxa_throw () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#6  0x00007ffff7ec901c in operator new(unsigned long) ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#7  0x00007ffff7f5643f in void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag) ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#8  0x0000555555559325 in Student::getFirstName[abi:cxx11]() const (this=0x7fffffffdb20)
    at Student.cpp:56
#9  0x0000555555556de1 in main (argc=2, argv=0x7fffffffe518) at main.cpp:137

*/
template <class T>
class Node
{
	public:
		T *value;
		struct Node *left;
		struct Node *right;
		

		Node(T *newValue) 
		{ 
			this->value=newValue;
			this->left=NULL;
			this->right=NULL;
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
	if(this==NULL)
		return NULL;
	if(defaultCompare(*this->value,*target)==0)
		return this->value;
	if(defaultCompare(*this->value,*target)==1)
		return left->search(target,defaultCompare);
	if(defaultCompare(*this->value,*target)==1)
		return right->search(target,defaultCompare);
} /* search */

/***************************************************/

template <class T>
bool Node<T>::insert(T *newItem, int (*defaultCompare)(T, T))
{	
	if(this->value==NULL){
		this->value=newItem;
		return true;
	}
	if(defaultCompare(*this->value,*newItem)==0){
		return false;
	}
	if(defaultCompare(*this->value,*newItem)==1){
		if(this->left==NULL){
			Node *newLeftNode=new Node(newItem);
			this->left=newLeftNode;
			return true;
		}
		return left->insert(newItem,defaultCompare);
	}
		
	if(defaultCompare(*this->value,*newItem)==-1){
		if(this->right==NULL){
			Node *newRightNode=new Node(newItem);
			this->right=newRightNode;
			return true;
		}
		return right->insert(newItem,defaultCompare);
	}
	return true;
		
} /* insert */

/***************************************************/

template <class T>
bool Node<T>::remove(T *target, int (*defaultCompare)(T, T))
{
	/*if(defaultCompare(*target,*this->value)=-1){
		if(left==NULL)
			return false;
		return left->remove(target,defaultCompare);
	}
	if(defaultCompare(*target,*this->value)==1){
		if(right==NULL)
			return false;
		return right->remove(target,defaultCompare);
	}
	if(defaultCompare(*target,*this->value)==0){
		Node *temp=this;
		if(left==NULL&&right==NULL){
			this=NULL;
			delete temp;
			return true;
		}
		if(left==NULL){
			this=this->right;
			delete temp;
			return true;
		}
		Node *temporary=this->left;
		while(temporary->right!=NULL){
			temporary=temporary->right;
		}
	}
	return false;*/
	
} /* remove */

/***************************************************/

template <class T>
void Node<T>::traverse(void (*visit)(T))
{
	if(left!=NULL){
		left->traverse(visit);
	}
	visit(*this->value);
	if(right!=NULL){
		right->traverse(visit);
	}
} /* traverse */

/***************************************************/

template <class T>
double Node<T>::traverseDouble(double initialValue, double (*visit)(double, T))
{	
	if(left!=NULL){
		initialValue+=left->traverseDouble(initialValue,visit);
	}
	initialValue+=visit(initialValue,*this->value);
	if(right!=NULL){
		initialValue+=right->traverseDouble(initialValue,visit);
	}
	return initialValue;
} /* traverse double */

/***************************************************/

template <class T>
int Node<T>::traverseInt(int initialValue, int (*visit)(int, T))
{
	if(left!=NULL){
		initialValue+=left->traverseInt(initialValue,visit);
	}
	initialValue+=visit(initialValue,&this->value);
	if(right!=NULL){
		initialValue+=right->traverseInt(initialValue,visit);
	}
	return initialValue;
} /* traverse int */

/***************************************************/

template <class T>
void Node<T>::traverseOut(ofstream *f, void (*visit)(ofstream *, T))
{
	if(left!=NULL){
		left->traverseOut(f,visit);
	}
	visit(f,*this->value);
	if(right!=NULL){
		right->traverseOut(f,visit);
	}
} /* traverse out */

/***************************************************/

#endif
