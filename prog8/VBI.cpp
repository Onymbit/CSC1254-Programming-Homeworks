#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>

#include "VBI.h"

using namespace std;

/***************************************************/

VBI::VBI()
{
	digits = "0";
	isNeg = false;
}

/***************************************************/

VBI::VBI(int x)
{
	isNeg = x < 0;
	digits = to_string(x * (isNeg ? -1 : 1));
}

/***************************************************/
	
VBI::VBI(long long int x)
{
	isNeg = x < 0;
	digits = to_string(x * (isNeg ? -1 : 1));
}

/***************************************************/
	
VBI::VBI(unsigned long long int x)
{
	isNeg = false;
	digits = to_string(x * (isNeg ? -1 : 1));
}

/***************************************************/
	
VBI::VBI(string x)
{
	/* if string x has values that are not numeric, return prefix */
	int index = 0;
	if(x[index] == '-')
	{
		index++;
		isNeg = true;
	}
	else
		isNeg = false;
		
	digits = "";
	while(index < x.length())
	{
		if(x[index] < '0' || x[index] > '9')
			break;
		digits += x[index];
		index++;
	}
	if(digits == "")
	{
		isNeg = false;
		digits = "0";
	}
}

/***************************************************/
	
VBI::VBI(const VBI &x)
{
	isNeg = x.getIsNeg();
	digits = x.getDigits();
}

/***************************************************/
	
VBI::~VBI(){}
	
/***************************************************/

string VBI::toString(void) const
{
	return (isNeg ? "-" : "") + digits;
}

/***************************************************/

bool VBI::operator> (const VBI& rhs) const
{	
	/** Suggested algorithm: */
	/* check signs */	
	/* check lengths of digit strings */
	/* check digits individually until there is a difference */
	if(this->isNeg&&!rhs.getIsNeg()){
		return false;
	}
	else if(!this->isNeg&&rhs.getIsNeg()){
		return true;
	}
	else{
		if(this->isNeg){
			if(this->digits.length()>rhs.getDigits().length())
				return false;
			if(this->digits.length()<rhs.getDigits().length())
				return true;
			for(int i=0;i<this->digits.length();i++){
				if(this->digits.at(i)<rhs.getDigits().at(i))
					return true;
				else return false;
			}	
		}
		if(this->digits.length()>rhs.getDigits().length())
				return !false;
			if(this->digits.length()<rhs.getDigits().length())
				return !true;
			for(int i=0;i<this->digits.length();i++){
				if(this->digits.at(i)<rhs.getDigits().at(i))
					return !true;
				else return !false;
			}
	}
	
	/* your code goes here */
} /* greater than */

/***************************************************/

bool VBI::operator< (const VBI& rhs) const
{	
	return rhs > *this;

} /* less than */

/***************************************************/

bool VBI::operator>= (const VBI& rhs) const
{
	return (*this > rhs) || (*this == rhs);
} /* greater than or equal to */

/***************************************************/

bool VBI::operator<= (const VBI& rhs) const
{	
	return (*this < rhs) || (*this == rhs);

} /* less than or equal to */

/***************************************************/

bool VBI::operator== (const VBI& rhs) const
{	
	return !(rhs > *this) && !(rhs < *this);
	
} /* equal to */

/***************************************************/

bool VBI::operator!= (const VBI& rhs) const
{	
	return !(*this == rhs);
	
} /* not equal */

/***************************************************/

VBI absoluteAdd(VBI a, VBI b)
{
	/* This function is optional.
	 * 
	 * Add the absolute values of a and b together
	 * and return the results.  Ignore isNeg for both
	 * a and b, and return a positive value.
	 * The function may be useful in operator+ and/or operator- */
	 
	 /* your code goes here if you choose to write this function. */
	 VBI c;
	 int temp;
	 string sTemp;
	 if(a.getDigits().length()>b.getDigits().length()){
		sTemp=a.getDigits();
		for(int i=a.getDigits().length()-1;i!=0;i--){
			temp=(int)a.getDigits().at(i)+(int)b.getDigits().at(i);
			if(temp>=10){
				if(i==0){
					sTemp.insert(0,"1");
					sTemp[i+1]=temp-10;
				}
				else{
					sTemp[i-1]=(int)sTemp[i-1]+1;
					sTemp[i]=temp-10;	
				}
			}
			else sTemp[i]=temp;
		}
		c=VBI(sTemp);
		return c;
	 }
	 sTemp=b.getDigits();
	 for(int i=b.getDigits().length()-1;i!=0;i--){
			temp=(int)a.getDigits().at(i)+(int)b.getDigits().at(i);
			if(temp>=10){
				if(i==0){
					sTemp.insert(0,"1");
					sTemp[i+1]=temp-10;
				}
				else{
					sTemp[i-1]=(int)sTemp[i-1]+1;
					sTemp[i]=temp-10;	
				}
			}
			else sTemp[i]=temp;
		}
		c=VBI(sTemp);
		return c;
	
} /* absolute add */

/***************************************************/

VBI absoluteSub(VBI a, VBI b)
{
	/* This function is optional.
	 * 
	 * Calculate the difference between a and b.  Ignore isNeg for both
	 * a and b, and return a positive value.
	 * The function may be useful in operator+ and/or operator- */
	 
	 /* your code goes here if you choose to write this function. */
	if(a.getIsNeg())
		a.toggleIsNeg();
	if(b.getIsNeg())
		b.toggleIsNeg();
	VBI c;
	int temp;
	string sTemp;
	if(a>b){
		sTemp=a.getDigits();
		for(int i=a.getDigits().length()-1;i>-1;i--){
			temp=(int)a.getDigits().at(i)+(int)b.getDigits().at(i);
			if(temp<0){
				sTemp[i-1]=(int)sTemp[i-1]-1;
				sTemp[i]=temp+10;	
				}
			else sTemp[i]=temp;
		}
		c=VBI(sTemp);
		return c;
	}
	else if(a<b){
		sTemp=b.getDigits();
		for(int i=b.getDigits().length()-1;i>-1;i--){
			temp=(int)a.getDigits().at(i)+(int)b.getDigits().at(i);
			if(temp<0){
				sTemp[i-1]=(int)sTemp[i-1]-1;
				sTemp[i]=temp+10;
			}
			else sTemp[i]=temp;
		}
		c=VBI(sTemp);
		return c;
	}
	else{
		c=VBI(0);
		return c;
	}
	
} /* absolute sub */

/***************************************************/

VBI VBI::operator+ (const VBI& rhs) const
{
	/** Suggested algorithm: */
	/* if isNeg is the same for *this and rhs, 
	 * 		run absoluteAdd
	 * otherwise,
	 * 		run absoluteSub
	 * */
	 
	 
	/* Your code goes here */
/*if(this->isNeg&&rhs.getIsNeg()||!(this->isNeg&&rhs.getIsNeg())){
		this->digits=absoluteAdd(*this,rhs).getDigits();
		return *this;
	}
	else{
		if(this->isNeg){
			this->toggleIsNeg();
			if(*this>rhs){
				this->toggleIsNeg();
				this->digits=absoluteSub(*this,rhs).getDigits();
			}
			this->digits=absoluteSub(*this,rhs).getDigits();
			return *this;	
		}	
		if(rhs.getIsNeg()){
			rhs.toggleIsNeg();
			if(*this<rhs){
				this->toggleIsNeg();
				this->digits=absoluteSub(*this,rhs).getDigits();
			}
			this->digits=absoluteSub(this,rhs).getDigits();
			return *this;
		}
	}*/
	VBI thisReplacer=*this;
	VBI rhsReplacer=rhs;
	if(this->isNeg&&rhs.getIsNeg()||!(this->isNeg&&rhs.getIsNeg())){
		thisReplacer.digits=absoluteAdd(*this,rhs).getDigits();
		return thisReplacer;
	}
	else{
		if(this->isNeg){
			thisReplacer.toggleIsNeg();
			if(thisReplacer>rhs){
				thisReplacer.toggleIsNeg();
			}
			thisReplacer.digits=absoluteSub(*this,rhs).getDigits();
			return thisReplacer;	
		}	
		if(rhs.getIsNeg()){
			rhsReplacer.toggleIsNeg();
			if(*this<rhsReplacer){
				thisReplacer.toggleIsNeg();
				thisReplacer.digits=absoluteSub(*this,rhs).getDigits();
			}
			thisReplacer.digits=absoluteSub(*this,rhs).getDigits();
			return thisReplacer;
		}
	
}
} /* plus */

/***************************************************/

VBI VBI::operator- (const VBI& rhs) const
{
	/** Suggested algorithm: */
	/* Create alternativeRhs which is -rhs
	 * return (*this) + alternativeRhs
	 * */
	 
	/* Your code goes here */
	VBI altRhs=rhs;
	altRhs.toggleIsNeg();
	return (*this) + altRhs;

} /* minus */

/***************************************************/

void VBI::doubleVBI()
{
	/* This function is optional.
	 * 
	 * Double the value of *this->
	 * The function may be useful in operator* and/or operator/
	 * */
	
	/* Your code goes here */
	int temp;
	string sTemp=this->digits;
	for(int i=this->digits.length()-1;i>-1;i++){
		temp=(int)this->digits[i]*2;
		if(temp>=10){
				if(i==0){
					sTemp.insert(0,"1");
					sTemp[i+1]=temp-10;
				}
				else{
					sTemp[i-1]=(int)sTemp[i-1]+1;
					sTemp[i]=temp-10;	
				}
			}
			else sTemp[i]=temp;
	}
	this->digits=sTemp;

} /* double */
	
/***************************************************/

void VBI::halfVBI()
{
	/* This function is optional.
	 * 
	 * Cut the value of *this in half, rounding down to
	 * the nearest whole number if *this is odd.
	 * The function may be useful in operator* and/or operator/
	 * */
	 
	/* Your code goes here */
	int temp;
	string sTemp=this->digits;
	for(int i=this->digits.length()-1;i>-1;i++){
		temp=(int)this->digits[i]/2;
		
			if(i==0&&temp==0&&this->digits.length()!=1){
				sTemp.erase(0);
			}
			else{
				sTemp[i]=temp;
			}
	}
	this->digits=sTemp;
} /* half */

/***************************************************/

VBI VBI::operator* (const VBI& rhs) const
{
	/** Suggested algorithm: */
	/* if either is zero, then return zero */
	/* if either is 1, then return the other value */
	/* retVal = absolute value of this */
	/* r = absolute value of rhs */
	/* while r > 1 */
		/* if r is even */
			/* halve r */
			/* double retVal */
		/* else */
			/* return retVal + retVal * (r-1) */
	/* set retVal.isNeg */
	/* return retVal */

	/* Your code goes here */
	if(*this==VBI(0)||rhs==VBI(0))
		return VBI(0);
	if(*this==VBI(1))
		return rhs;
	if(rhs==VBI(1))
		return *this;
	VBI retVal=*this;
	if(retVal.getIsNeg())
		retVal.toggleIsNeg();
	VBI r=rhs;
	if(r.getIsNeg())
		r.toggleIsNeg();
	while(r>VBI(1)){
		if(r%VBI(2)==VBI(0)){
			r.halfVBI();
			retVal.doubleVBI();
		}
		else{
			return retVal+retVal*(r-VBI(1));
		}
	}
	if(this->isNeg==rhs.getIsNeg()){
		return retVal;
	}
	else{
		retVal.toggleIsNeg();
		return retVal;
	}
	
	
} /* multiply */

/***************************************************/

VBI VBI::operator/ (const VBI& rhs) const
{
	/** Suggested algorithm: */
	/* set retVal and r to the absolute values of *this and rhs respectively */
	/* if retVal < r, then return zero */
	/* calculate return value's isNeg */
	/* if retVal == r, return 1 or -1 depending on return value's isNeg */
	/* while r is even */
		/* cut r and retVal each in half */
	/* use binary search between 1 and retVal to find a value such that
	 * 		r * retVal >= retVal and r * (retVal - 1) < retVal */
	/* set retVal's isNeg */
	/* return retVal */
	
	/* Your code goes here */
	VBI retVal=*this;
	if(retVal.getIsNeg())
		retVal.toggleIsNeg();
	VBI r=rhs;
	if(r.getIsNeg())
		r.toggleIsNeg();
	if(retVal<r)
		return VBI(0);
	bool retIsNeg=(this->isNeg&&rhs.getIsNeg());
	if(retVal==r){
		if(retIsNeg)
			return VBI(-1);
		else return VBI(1);
	}
	while(r%VBI(2)==0){
		retVal.halfVBI();
		r.halfVBI();
	}
	VBI mid,i,f=retVal;
	while(i<=retVal){
		mid=i+(f-i)/VBI(2);
		if(mid==r*retVal&&r*retVal>=retVal&&r*(retVal-VBI(1))<retVal)
			break;
		if(mid<r*retVal&&r*retVal>=retVal&&r*(retVal-VBI(1))<retVal)
			i=mid+VBI(1);
		else f=mid-VBI(1);	
	}
	
	retVal=mid;
	if(retIsNeg)
		retVal.toggleIsNeg();
	return retVal;
	
	
} /* divide */

/***************************************************/

VBI VBI::operator% (const VBI& rhs) const
{
	/* I've just decided to write this function for you.
	 * You're welcome. */
	return *this - (*this / rhs) * rhs;
} /* mod */

/***************************************************/

VBI VBI::operator= (const VBI& rhs)
{
	/* This one, too. */
	this->digits = rhs.getDigits();
	this->isNeg = rhs.getIsNeg();
	return *this;
} /* assignment */
	
/***************************************************/

VBI VBI::operator++ (void) /* prefix ++ operator */
{
	/* Your code goes here */
	return *this+VBI(1);
	
} /* increment */

/***************************************************/

VBI VBI::operator-- (void) /* prefix -- operator */
{
	/* Your code goes here */
	return *this-VBI(1);
} /* decrement */

/***************************************************/

VBI VBI::operator++ (int) /* postfix ++ operator */
{
	/* Your code goes here */
	return *this+VBI(1);

} /* increment */

/***************************************************/

VBI VBI::operator-- (int) /* postfix -- operator */
{
	/* Your code goes here */
	return *this-VBI(1);
} /* decrement */

/***************************************************/
/***************************************************/
/***************************************************/
