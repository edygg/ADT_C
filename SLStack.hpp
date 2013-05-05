#ifndef SLSTACK_HPP
#define SLSTACK_HPP

#include "Object.hpp"
#include "ADTStack.hpp"
#include "SLNode.hpp"

class SLStack : public ADTStack
{
public:
	SLStack();
	virtual ~SLStack();
	virtual bool push(Object*);
	virtual Object* pop();
	virtual Object* peek() const;

private:
	SLNode* head;
};

#endif