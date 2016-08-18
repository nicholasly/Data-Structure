#include <iostream>
#include "LinearList.h"

template <class T>
struct LinkNode {           //  The Definition of Link Node 
	T data;                 //  Data Domain
	LinkNode<T> * link;     //  Link Pointer Domain
	LinkNode(LinkNode<T> * ptr = NULL) {link = ptr;}
    //  Construtor for the Intialization of Pointer only
    LinkNode(const T& item, LinkNode<T> * ptr = NULL) {
    	data = item;
    	link = ptr;
    }  //  Construtor for the Intialization of Data and Pointer
};

template <class T>
class List : public LinearList<T> {
public:
	List() {
		first = new LinkNode<T>;   //  Default Constructor
	}
	List(const T& x) {
		first = new LinkNode<T>(x);
	}  //  Constructor
	List(List<T>& L);  //  Copy Constructor
	~List() {makeEmpty();}  //  Destructor
	void makeEmpty();  //  Set the Linked List Empty
	int Length() const;  //  Return the Length of Linked List
	LinkNode<T> * getHead() const {return first;}
	//  Return the Address of Additional Head Node
	LinkNode<T> * Search(T x);  //  Search for the element containing x
    LinkNode<T> * Locate(int i);  //  Search for the Address of the ith Element
    bool getData(int i, T& x) const;  //  Get the Value of the ith Element
    void setData(int i, T& x);  //  Use x to Change the Value of the ith Element
    bool Insert(int i, T& x);  //  Insert x After the ith Element
    bool Remove(int i, T& x);  //  Delete the ith Element x and Return the Value
    bool IsEmpty() const {
    	return first->link == NULL ? true : false;
    }  //  Judge if List is FULL and Return false if it is NOT FULL
    void Sort();  //  Sort
    void input();  //  input
    void output();  //  output
    List<T>& operator=(List<T>& L);  //  Overload the Function
protected:
	LinkNode<T> * first;
};
