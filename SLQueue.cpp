#include "SLQueue.hpp"

SLQueue::SLQueue() : ADTQueue() {
	head = NULL;
}

SLQueue::~SLQueue() {
	if (head)
		delete head;
}

bool SLQueue::queue(Object* E) {
	SLNode* neo = new SLNode(E);

	if (!neo)
		return false;

	if (isEmpty())
		head = neo;
	else {
		SLNode* tmp = head;

		for (int i = 0; i < size - 1; i++)
			tmp = tmp->getNext();

		tmp->setNext(neo);
	}

	size++;
	return true;
}

Object* SLQueue::dequeue() {
	if (isEmpty())
		return NULL;

	SLNode* rem = head;
	head = head->getNext();
	Object* retval = rem->getData();

	rem->setData(NULL);
	rem->setNext(NULL);
	delete rem;

	size--;
	return retval;
}

Object* SLQueue::peek() const {
	return head->getData();
}