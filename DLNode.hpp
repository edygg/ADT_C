#ifndef DLNODE_HPP
#define DLNODE_HPP

#include "Object.hpp"

class DLNode : Object 
{
public:
	DLNode(Object*);
	virtual ~DLNode();
	void setNext(DLNode*);
	DLNode* getNext() const;
	void setPrev(DLNode*);
	DLNode* getPrev() const;
	void setData(Object*);
	Object* getData() const;

private:
	DLNode* next;
	DLNode* prev;
	Object* data;
};

#endif