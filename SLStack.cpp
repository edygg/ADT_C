#include "SLStack.hpp"

SLStack::SLStack() : ADTStack() {
	head = NULL;
}

SLStack::~SLStack() {
	if (head)
		delete head;
}

bool SLStack::push(Object* E) {
	SLNode* neo = new SLNode(E);

	if (!neo)
		return false;

	if (isEmpty())
		head = neo;
	else {
		neo->setNext(head);
		head = neo;
	}

	size++;
	return true;
}

Object* SLStack::pop() {
	if (isEmpty())
		return NULL;

	SLNode* rem = head;
	Object* retval = NULL;

	head = head->getNext();
	rem->setNext(NULL);
	retval = rem->getData();
	rem->setData(NULL);
	delete rem;
	size--;

	return retval;
}

Object* SLStack::peek() const {
	return head->getData();
}