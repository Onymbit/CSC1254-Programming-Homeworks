/*
        Author: Jameson Connor Harrington
        OrderedList.cpp
         
        Your beloved instructer has lovingly provided you with a skeleton
        file for the Ordered List class.  All the functions are 
        there; you just need to provide the guts.
         
        Happy coding!!!
*/

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "OrderedList.h"

using namespace std;

/***************************************************/

OrderedList::OrderedList() //constructer
{ 
	
}

/***************************************************/

OrderedList::~OrderedList() 
{
}

/***************************************************/

int OrderedList::getSize()
{
	return size;
}

/***************************************************/

Student *OrderedList::search(string lastName, string firstName)
{   /* If target exists in list, return pointer to the target
	 * otherwise, return null
	 * *
	return nodes[1];*/
	for(int i=0;i<size;i++){
		if(lastName==nodes[i].getLastName()&&firstName==nodes[i].getFirstName()){	
			return &nodes[i];
		}
					
	}
	return NULL;
} /* search */

/***************************************************/

bool OrderedList::insert(Student newItem)
{  /* If new item exists in list, or list is full, return false
	* otherwise, add item to list, increment size, and return true */
	if(size==100)
		return false;
	for(int i=0;i<size;i++){
		if(newItem.getLastName()==nodes[i].getLastName()&&newItem.getFirstName()==nodes[i].getLastName())
			return false;		
	}
	for(int j=0;j<size+1;j++){
		nodes[size-j]=nodes[size-1-j];
		if((string)(nodes[size-j].getLastName()+nodes[size-j].getFirstName())<=(string)(newItem.getLastName()+newItem.getFirstName())){
			nodes[size-j]=newItem;
			return true;
		}
	}
	
		
} /* insert */


/***************************************************/

bool OrderedList::remove(string lastName, string firstName)
{
	for(int i=0;i<size;i++){
		if(lastName==nodes[i].getLastName()&&firstName==nodes[i].getFirstName()){
			for(int j=i;j<size-1;j++){
				nodes[j]=nodes[j+1];
			}
			size--;
			return true;
		}
	}
	return false;
}

/***************************************************/

void OrderedList::traverse(void)
{   /* For each student, print the student's order, name, and letter grade in the following format:
	 * order <tab> lastName, firstName - <grade>
	 * 
	 * For example, the second student in the roster, whose name is 
	 * Bridgett Avendado and whose grade is D would appear as follows:
	 * 2.	Cassel, Beth - A
	 * 
	 * The students are listed in lexicographical order by their last name,
	 * with 2 or more students having the same last name being listed in
	 * lexicographical order by their first name.
	 * */
	for(int i=0;i<size;i++){
		cout<<(1+i)<<".\t"<<nodes[i].getLastName()<<", "<<nodes[i].getFirstName()<<"\t- "<<nodes[i].letterGrade()<<endl;
	}
} /* traverse */

/***************************************************/

void OrderedList::traverseByGrade(void)
{

} /* traverse by grade */

/***************************************************/

void OrderedList::traverseOut(ofstream *f, double hwWeight, double qzWeight, double fxWeight)
{

}

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
