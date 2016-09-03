#include <iostream>
#include <math.h>
#include "Polynomal.h"
using namespace std;

Term * Term::InsertAfter(float c, int e) {
	link = new Term(c, e, link);
}

ostream& operator << (ostream& out, const T& x) {
	if (x.coef == 0.0) return out;  //  no output when the coefficient is 0
	out << x.coef;  //   the output of the coefficient
	switch(x.exp) {
		case 0 : break;
		case 1 : out << "X"; break;
		default : out << "X" << x.exp; break;
	}
	return out;
}

Polynomal::Polynomal(Polynomal& R) {
	first = new Term(0, -1);
	Term * destptr = first, * srcptr = R.getHead()->link;
	while (srcptr != NULL) {
		destptr->InsertAfter(srcptr->coef, srcptr->exp);
		srcptr = srcptr->link;
		destptr = destptr->link;
	}
}

int Polynomal::maxOrder() {
	Term * current = first;
	while (current->link != NULL)
		current = current->link;
	return current->exp;
}

ostream& operator << (ostream& in, const Polynomal& x) {
	Term * rear = x.getHead();
	int c, e;
	while(1) {
		cout << "Input a term(coef, exp): " << endl;
		in >> c >> e;
		if (e < 0) break;
		rear  = rear->InsertAfter(c, e);
	}
	return in;
}

istream& operator >> (istream&, Polynomal&) {
	Term * current = x.getHead()->link;
	cout << "The polynomal is: " << endl;
	bool h = true;
	while (current ! = NULL) {
		if (h == false && current->coef> 0.0) out << "+";
		h = false;
		cout << * current;
		current = current->link;
	}
	out << endl;
	return out;
}

Polynomal operator + (Polynomal& A, Polynomal& B) {
	Term * pa, * pb, * pc, * p;
	float temp;
	Polynomal C;
	pc = C.first;

	pa = A.getHead()->link;
	pb = B.getHead()->link;

	while (pa != NULL && pb != NULL) {
		if (pa->exp == pb->exp) {
			term = pa->coef + pb->coef;
			// the addition of the coefficients
			if (fabs(temp) > 0.001)
				//  the coefficient is not 0
				pc = pc->InsertAfter(temp, pa->exp);
			    pa = pa->link; pb = pb->link;
			}
	}
	else if (pa->exp < pb->exp) {
		// the exponent of pa is smaller
		pc = pc->InsertAfter(pa->coef, pa->exp);
		pa = pa->link;
	} else {
		// the exponent of pb is smaller
		pc = pc->InsertAfter(pb->coef, pb->exp);
		pb = pb->link;
	}
	if (pa != NULL) p = pa;
	else p = pb;
	while (p != NULL) {
		pc = pc->InsertAfter(p->coef, p->exp);
		p = p->link;
	}
	return C;
}

Polynomal operator * (Polynomal& A, Polynomal& B) {
	Term * pa, * pb, *pc;
	//  the head pointer of the linked list
	int AL, BL, i, k, maxExp;
	Polynomal C;
	//  the returned polynomal
	pc = C.getHead();
	//  the last pointer of the returned polynomal
	AL = A.maxOrder(); BL = B.maxOrder();
	//  the exponents of two polynomals
	if (AL != -1 || BL != -1) {
		//  check if one of the polynomals is 0
		maxExp = AL + BL;   
		//  the maximal exponent of the returned polynomal
		float * result = new float[maxExp + 1];
		for (int i = 0; i <= maxExp; i++) {
			result[i] = 0.0;
		}
		pa = A.getHead()->link;
		//  the pointer used to follow the calculation
		while (pa != NULL) {
			pb = B.getHead()->link;
			while (pb != NULL) {
				k = pa->exp + pb->exp;  // the exponent of the result 
				result[k] += pa->coef * pb->coef;
				pb = pb->link;
				//  the pointer used to follow the calculation
			}
			pa = pa->link;
		}
		//  the result is formed in the array result
		for (i = 0; i <= maxExp; i++) {
			if (fabs(result[i]) > 0.001)
				pc = pc->InsertAfter(result[i], i);
		}
		delete [] result;
	}
	pc->link = NULL;
	return C;
}
