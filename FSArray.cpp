#include "FSArray.hpp"

FSArray::FSArray(unsigned int c) : ADTList() {
	capacity = c;
	data = new Object*[capacity];
}

FSArray::~FSArray() {
	delete[] data;
}

bool FSArray::insert(Object* E, unsigned int p) {
	/*	Precondiciones	*/
	if (isFull())
		return false;
	if (!(p >= 0 && p <= size))
		return false;

	/*	Si la lista está vacía o se está insertando
		al final de la lista puede asignarse sin 
		ningún inconveniente a la lista.
	*/
	if (isEmpty() || p == size)
		data[p] = E;
	else {
	/*	Si se inserta en medio de la lista se
		necesita mover los elementos contiguos
		para dejar libre la casilla del elemento
		en el arreglo. 
	*/
		for (int i = size; i > p; i--)
			data[i] = data[i - 1];

		data[p] = E;
	}

	size++;
	return true;
}

Object* FSArray::remove(unsigned int p) {
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

Object* FSArray::first() const {
	if (isEmpty())
		return NULL;

	return data[0];
}

Object* FSArray::last() const {
	if (isEmpty())
		return NULL;

	return data[size - 1]; 
}

int FSArray::getCapacity() const {
	return capacity;
}

bool FSArray::isFull() const {
	return size == capacity;
}

void FSArray::clear() {
	delete[] data;

	data = new Object*[capacity];
	size = 0;
}

int FSArray::indexOf(Object* E) const {
	for (int i = 0; i < size; i++) {
		if(data[i]->equals(E))
			return i;
	}

	return -1;
}

Object* FSArray::get(unsigned int p) const {
	if(isEmpty())
		return NULL;
	if(!(p >= 0 && p < size))
		return NULL;

	return data[p];
}

