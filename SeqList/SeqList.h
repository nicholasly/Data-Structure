#include <iostream>
#include <stdlib.h>
#include "LinearList.h"
const int defaultSize = 100;
template <class T>
class SeqList : public LinearList<T> {
protected:
	T * data;
	int maxSize;
	int last;
	void reSize(int newSize);
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);
	~SeqList() {
		delete[] data;
	}
	int Size() const {
		return maxSize;
	}
	int Length() const {
		return last + 1;
	}
	int Search(T& x) const;
	int Locate(int i) const;
    bool getData(int i, T& x) const {
    	if (i > 0 && i <= last + 1) {
    		x = data[i - 1];
    		return true;
    	}
    	return false;
    }
    void setData(int i, T& x) {
    	if (i > 0 && i <= last + 1) data[i - 1] = x;
    }
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
    bool IsEmpty() {
    	return (last == maxSize) ? true : false;
    }
    bool IsFull() {
    	return (last == maxSize - 1) ? true : false;
    }
    void input();
    void output();
    
};
