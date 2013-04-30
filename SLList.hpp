#ifndef SLLIST_HPP
#define SLLIST_HPP

#include "ADTList.hpp"
#include "SLNode.hpp"
#include "Object.hpp"

class SLList : public ADTList
{
public:
	SLList();
	virtual ~SLList();
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
	SLNode* head;
};

#endif