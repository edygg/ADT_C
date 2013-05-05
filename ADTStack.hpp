#ifndef ADTSTACK_HPP
#define ADTSTACK_HPP

#include "Object.hpp"

class ADTStack : public Object 
{
public:
	ADTStack();
	virtual ~ADTStack();
	virtual bool push(Object*) = 0;
	virtual Object* pop() = 0;
	virtual Object* peek() const = 0;
	bool isEmpty() const;

protected:
	unsigned int size;
};

#endif