#ifndef SLNODE_HPP
#define SLNODE_HPP

#include "ADTList.hpp"
#include "Object.hpp"

class SLNode : public Object
{
public:
	SLNode(Object*);
	~SLNode();
	void setData(Object*);
	Object* getData() const;
	void setNext(SLNode*);
	SLNode* getNext() const;
private:
	Object* data;
	SLNode* next;
};

#endif