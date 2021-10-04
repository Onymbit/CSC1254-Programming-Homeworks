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
#include <iomanip>
#include <iostream>
#include <fstream>
#include "OrderedList.h"

using namespace std;

/***************************************************/

OrderedList::OrderedList() //constructer
{ 
	size=0;
	
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
		if(nodes[i].isEqualToName(&newItem)){
		return false;
		}
					
	}
	if(size==0){
		nodes[0]=newItem;
		size++;
		return true;	
	}
		
	for(int j=0;j<size;j++){
		nodes[size-j]=nodes[size-j-1];
		if(nodes[size-j].isLessThanName(&newItem)){
			nodes[size-j]=newItem;
			size++;
			return true;
		}
	}
	return false;
	
		
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
		
		cout<<(1+i)<<'\t'<<left<<setw(12)<<nodes[i].getLastName()+", "<<setw(12)<<nodes[i].getFirstName()<<"- "<<nodes[i].letterGrade()<<endl;
	}
} /* traverse */

/***************************************************/

void OrderedList::traverseByGrade(void)
{
	int count=1;
	for(int i=0;i<size;i++){
		if(nodes[i].letterGrade()=='A'){
			cout<<(count)<<'\t'<<left<<setw(12)<<nodes[i].getLastName()+", "<<setw(12)<<nodes[i].getFirstName()<<"- "<<nodes[i].letterGrade()<<endl;
			count++;
		}		
	}
	for(int j=0;j<size;j++){
		if(nodes[j].letterGrade()=='B'){
			cout<<(count)<<'\t'<<left<<setw(12)<<nodes[j].getLastName()+", "<<setw(12)<<nodes[j].getFirstName()<<"- "<<nodes[j].letterGrade()<<endl;
			count++;
		}		
	}
	for(int k=0;k<size;k++){
		if(nodes[k].letterGrade()=='C'){
			cout<<(count)<<'\t'<<left<<setw(12)<<nodes[k].getLastName()+", "<<setw(12)<<nodes[k].getFirstName()<<"- "<<nodes[k].letterGrade()<<endl;
			count++;
		}
			
	}
	for(int l=0;l<size;l++){
		if(nodes[l].letterGrade()=='D'){
			cout<<(count)<<'\t'<<left<<setw(12)<<nodes[l].getLastName()+", "<<setw(12)<<nodes[l].getFirstName()<<"- "<<nodes[l].letterGrade()<<endl;
			count++;
		}
			
	}
	for(int f=0;f<size;f++){
		if(nodes[f].letterGrade()=='F'){
			cout<<(count)<<'\t'<<left<<setw(12)<<nodes[f].getLastName()+", "<<setw(12)<<nodes[f].getFirstName()<<"- "<<nodes[f].letterGrade()<<endl;
			count++;
		}
			
	}
} /* traverse by grade */

/***************************************************/

void OrderedList::traverseOut(ofstream *f, double hwWeight, double qzWeight, double fxWeight)
{
	/* The file *f should already be open prior to calling traverseOut.
	 * 
	 * First, output to *f the weights and number of students, then for each student, 
	 * output the student's name, homework grades, quiz grades, and exam grade to *f.
	 * */
	*f<<hwWeight<<'\n';
	*f<<qzWeight<<'\n';
	*f<<fxWeight<<'\n';
	*f<<size<<'\n';
	for(int i=0;i<size;i++){
		*f<<nodes[i].getLastName()<<'\t';
		*f<<nodes[i].getFirstName();
		for(int j=0;j<4;j++)
			*f<<'\t'<<nodes[j].getHWScore(j);
		for(int k=0;k<4;k++)
			*f<<'\t'<<nodes[k].getQuizScore(k);
		*f<<'\t'<<nodes[i].getFinalExam()<<'\n';
	}
	
}

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
