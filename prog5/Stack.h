/* Jameson Connor Harrington
Stack.h*/

using namespace std;

template <class T>
class Stack{
	private:
		int size;
		struct Node
		{
			T value;
			struct Node *nextNode;
		};
		Node *firstNode;
	public:
		Stack();
		~Stack();
		bool isEmpty();
		void push(T newItem);
		bool pop();
		T top();
};
template <class T>
Stack<T>::Stack(){
	size=0;
	firstNode=NULL;
}
template <class T>
Stack<T>::~Stack(){
	while(size!=0){
		this->pop();
	}
}
template <class T>
bool Stack<T>::isEmpty(){
	if(size==0)
		return true;
	return false;
}
template <class T>
void Stack<T>::push(T newItem){
	Node *newNode= new Node();
	newNode->value=newItem;
	newNode->nextNode=NULL;
	
	if(size==0){
		firstNode=newNode;
		size++;
	}
	else{
		newNode->nextNode=firstNode;
		firstNode=newNode;
		size++;
	}
	
}
template <class T>
bool Stack<T>::pop(){
	if(size==0)
		return false;
	Node *toRemove;
	toRemove=firstNode;
	if(size==1){
		firstNode=NULL;
		size--;
		delete toRemove;
		return true;
	}
	firstNode=toRemove->nextNode;
	size--;
	delete toRemove;
	return true;
}

template <class T>
T Stack<T>::top(){
	if(size!=0)
		return firstNode->value;
	return NULL;
}

