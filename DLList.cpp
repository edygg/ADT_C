#include "DLList.hpp"

DLList::DLList() {
	head = NULL;
}

DLList::~DLList() {
	if (head)
		delete head;
}

bool DLList::insert(Object* E, unsigned int p) {
	if(!(p >= 0 && p <= size))
		return false;

	DLNode* neo = new DLNode(E);

	if (!neo)
		return false;

	if (isEmpty())
		head = neo;
	else {
		if (p == 0) {
			neo->setNext(head);
			head->setPrev(neo);
			head = neo;
		} else {
			DLNode* tmp = head;

			for (int i = 0; i < p - 1; i++)
				tmp = tmp->getNext();
			
			if (tmp->getNext())
				tmp->getNext()->setPrev(neo);

			neo->setNext(tmp->getNext());
			tmp->setNext(neo);
			neo->setPrev(tmp);	
		}
	}
	size++;
	return true;
}

Object* DLList::remove(unsigned int p) {
	if (isEmpty())
		return NULL;
	if (!(p >= 0 && p < size))
		return NULL;

	DLNode* rem = head;
	Object* retval = NULL;

	if (p == 0) {
		head = head->getNext();

		if (head)
			head->setPrev(NULL);
	} else {
		for (int i = 0; i < p - 1; i++)
			rem = rem->getNext();

		DLNode* tmp = rem;
		rem = rem->getNext();
		tmp->setNext(rem->getNext());

		if (rem->getNext())
			rem->getNext()->setPrev(tmp);
	}

	retval = rem->getData();
	rem->setData(NULL);
	rem->setPrev(NULL);
	rem->setNext(NULL);
	delete rem;
	size--;
	return retval;
}

Object* DLList::first() const {
	if (isEmpty())
		return NULL;

	return head->getData();
}

Object* DLList::last() const {
	if (isEmpty())
		return NULL;

	DLNode* tmp = head;

	for (int i = 0; i < size - 1; i++)
		tmp = tmp->getNext();

	return tmp->getData();
}

int DLList::getCapacity() const {
	return -1;
}

bool DLList::isFull() const {
	return false;
}

void DLList::clear() {
	if (isEmpty())
		return;

	delete head;
	head = NULL;
	size = 0;
}

int DLList::indexOf(Object* E) const {
	if (isEmpty())
		return -1;

	DLNode* tmp  = head;

	for (int i = 0; i < size; i++) {
		if (tmp->getData()->equals(E))
			return i;

		tmp = tmp->getNext();
	}

	return -1;
}

Object* DLList::get(unsigned int p) const {
	if (isEmpty())
		return NULL;

	if (!(p >= 0 && p < size))
		return NULL;

	DLNode* tmp = head;

	for (int i = 0; i < p; i++)
		tmp = tmp->getNext();

	return tmp->getData();
}