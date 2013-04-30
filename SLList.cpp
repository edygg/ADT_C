#include "SLList.hpp"

SLList::SLList() {
	head = NULL;
}

SLList::~SLList() {
	if (head)
		delete head;
}

bool SLList::insert(Object* E, unsigned int p) {
	if (!(p >= 0 && p <= size))
		return false;

	SLNode* neo = new SLNode(E);

	if (!neo)
		return false;

	if (isEmpty())
		head = neo;
	else {
		if (p == 0) {
			neo->setNext(head);
			head = neo;
		} else {
			SLNode* tmp = head;

			for (int i = 0; i < p - 1; i++)
				tmp = tmp->getNext();

			neo->setNext(tmp->getNext());
			tmp->setNext(neo);
		}

	}

	size++;
	return true;
}

Object* SLList::remove(unsigned int p) {
	if (isEmpty())
		return NULL;
	if (!(p >= 0 && p < size))
		return NULL;

	SLNode* rem = head;
	Object* retval = NULL;

	if (p == 0) 
		head = head->getNext();
	else {
		for (int i = 0; i < p - 1; i++)
			rem = rem->getNext();

		SLNode* tmp = rem;
		rem = rem->getNext();
		tmp->setNext(rem->getNext());
	}

	retval = rem->getData();
	rem->setData(NULL);
	rem->setNext(NULL);
	delete rem;
	size--;
	return retval;
}

Object* SLList::first() const {
	if (isEmpty())
		return NULL;

	return head->getData();
}

Object* SLList::last() const {
	if (isEmpty())
		return NULL;

	SLNode* tmp = head;

	for (int i = 0; i < size - 1; i++)
		tmp = tmp->getNext();

	return tmp->getData();
}

int SLList::getCapacity() const {
	return -1;
}

bool SLList::isFull() const {
	return false;
}

void SLList::clear() {
	if (isEmpty())
		return;

	delete head;
	head = NULL;
	size = 0;
}

int SLList::indexOf(Object* E) const {
	if (isEmpty())
		return -1;

	SLNode* tmp = head;

	for (int i = 0; i < size; i++) {
		if (tmp->getData()->equals(E)) {
			return i;
		}
		tmp = tmp->getNext();
	}

	return -1;
}

Object* SLList::get(unsigned int p) const {
	if (isEmpty())
		return NULL;	
	if (!(p >= 0 && p < size))
		return NULL;

	SLNode* tmp = head;

	for (int i = 0; i < p; i++)
		tmp = tmp->getNext();

	return tmp->getData();
}