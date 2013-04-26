#ifndef ADTLIST_HPP
#define ADTLIST_HPP

#include "Object.hpp"

class ADTList : public Object 
{
	ADTList();
	virtual ~ADTList();
	virtual bool insert(Object*, int) = 0;
	virtual Object* first() const = 0;
	virtual Object* last() const = 0;
	int size() const;
	virtual int getCapacity() const = 0;
	bool isEmpty() const;
	virtual bool isFull() const = 0;
	virtual void clear() = 0;
	virtual int indexOf(Object*) const = 0;
	virtaul Object* get(int p) const = 0;
};

#endif