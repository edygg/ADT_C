#include "DSArray.hpp"

DSArray::DSArray() {
	capacity = 1;
	data = new Object*[capacity];
}

DSArray::~DSArray() {
	delete[] data;
}

bool DSArray::insert(Object* E, unsigned int p) {
	if (isFull())
		if (!makebigger())
			return false;
	if (!(p >= 0 && p <= size))
		return false;

	if (isEmpty() || p == size)
		data[p] = E;
	else {
		for (int i = size; i > p; i--)
			data[i] = data[i - 1];

		data[p] = E;
	}

	size++;
	return true;	
}

Object* DSArray::remove(unsigned int p) {
	if (isEmpty())
		return NULL;
	if (!(p >= 0 && p < size))
		return NULL;

	Object* retval = data[p];

	if (p == size - 1)
		data[p] = NULL;
	else {
		for (int i = p; i < size - 1; i++)
			data[i] = data[i + 1];

		data[size - 1] = NULL;
	}

	size--;
	return retval;
}

Object* DSArray::first() const {
	if (isEmpty())
		return NULL;

	return data[0];
}

Object* DSArray::last() const {
	if (isEmpty())
		return NULL;

	return data[size - 1];
}

int DSArray::getCapacity() const {
	return -1;
}

bool DSArray::isFull() const {
	return false;
}

void DSArray::clear() {
	delete[] data;

	data = new Object*[capacity];
	size = 0;
}

int DSArray::indexOf(Object* E) const {
	for (int i = 0; i < size; i++) {
		if(data[i]->equals(E))
			return i;
	}

	return -1;
}

Object* DSArray::get(unsigned int p) const {
	if(isEmpty())
		return NULL;
	if(!(p >= 0 && p < size))
		return NULL;

	return data[p];
}

bool DSArray::makebigger() {
	Object** tmp = new Object*[++capacity];
	
	if (!tmp)
		return false;

	for (int i = 0; i < size; i++)
		tmp[i] = data[i];

	data = NULL;
	data = tmp;

	return true;
}