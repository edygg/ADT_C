#ifndef FSARRAY_HPP
#define FSARRAY_HPP

#include "ADTList.hpp"

class FSArray : public ADTList
{
public:
	FSArray(unsigned int);
	virtual ~FSArray();
	virtual bool insert(Object*, unsigned int);
	virtual Object* remove(unsigned int);
	virtual Object* first() const;
	virtual Object* last() const;
	virtual int getCapacity() const;
	virtual bool isFull() const;
	virtual void clear();
	virtual int indexOf(Object*) const;
	virtual Object* get(unsigned int) const;

private:
	unsigned int capacity;
	Object** data;
};

#endif