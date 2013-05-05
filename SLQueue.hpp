#ifndef SLQUEUE_HPP
#define SLQUEUE_HPP

#include "Object.hpp"
#include "ADTQueue.hpp"
#include "SLNode.hpp"

class SLQueue : public ADTQueue
{
public:
	SLQueue();
	virtual ~SLQueue();
	virtual bool queue(Object*);
	virtual Object* dequeue();
	virtual Object* peek() const;

private:
	SLNode* head;
}; 

#endif