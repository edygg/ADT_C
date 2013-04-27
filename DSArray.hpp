#ifndef DSARRAY_HPP
#define DSARRAY_HPP

#include "ADTList.hpp"

class DSArray : public ADTList
{
public:
	DSArray();
	virtual ~DSArray();
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
	bool makebigger();
};

#endif