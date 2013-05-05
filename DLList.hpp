#ifndef DLLIST_HPP
#define DLLIST_HPP

#include "ADTList.hpp"
#include "DLNode.hpp"

class DLList : public ADTList
{
public:
	DLList();
	virtual ~DLList();
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
	DLNode* head;
};

#endif