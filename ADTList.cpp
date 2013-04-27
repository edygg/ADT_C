#include "ADTList.hpp"

ADTList::ADTList() : Object() {
	size = 0;
}

ADTList::~ADTList() {
	
}

unsigned int ADTList::getSize() const {
	return size;
}

bool ADTList::isEmpty() const {
	return size == 0;
}