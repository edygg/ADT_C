#ifndef ADTQUEUE_HPP
#define ADTQUEUE_HPP

#include "Object.hpp"

class ADTQueue : public Object
{
public:
	ADTQueue();
	virtual ~ADTQueue();
	virtual bool queue(Object*) = 0;
	virtual Object* dequeue() = 0;
	virtual Object* peek() const = 0;
	bool isEmpty() const;

protected:
	unsigned int size;
};

#endif