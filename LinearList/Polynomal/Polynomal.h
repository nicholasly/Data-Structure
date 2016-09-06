#ifndef POLYNOMAL_H
#define POLYNOMAL_H
#include <iostream>

struct Term {
	float coef;    //  coefficient
	int exp;
	Term * link;
	Term(float c, int e, Term * next = NULL)
	   {coef = c; exp = e; link = next;}
	Term * InsertAfter(float c, int e);
	friend std::ostream& operator << (std::ostream&, const Term&);	
};
//  The definition of the term of the polynomal

class Polynomal {  
public:
	Polynomal() {
		first = new Term(0, -1);
	}
	//  Constructor to establish an empty linked list
	Polynomal(Polynomal& R);
	//  Copy constructor
	int maxOrder();
	//  Calculate the maximal exponent
	Term * getHead() const {
		return first;
	}
private:
	Term * first;
	friend std::ostream& operator << (std::ostream&, const Polynomal&);
	friend std::istream& operator >> (std::istream&, Polynomal&);
	friend Polynomal operator + (Polynomal&, Polynomal&);
	friend Polynomal operator * (Polynomal&, Polynomal&);
};
//  The definition of the polynomal

#endif
