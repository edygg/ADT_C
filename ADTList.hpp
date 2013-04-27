#ifndef ADTLIST_HPP
#define ADTLIST_HPP

#include "Object.hpp"

class ADTList : public Object 
{
public:
	ADTList();
	virtual ~ADTList();
	virtual bool insert(Object*, unsigned int) = 0;
	virtual Object* remove(unsigned int) = 0;
	virtual Object* first() const = 0;
	virtual Object* last() const = 0;
	unsigned int getSize() const;
	virtual int getCapacity() const = 0;
	bool isEmpty() const;
	virtual bool isFull() const = 0;
	virtual void clear() = 0;
	virtual int indexOf(Object*) const = 0;
	virtual Object* get(unsigned int) const = 0;

protected:
	unsigned int size;
};

#endif