#include "ADTStack.hpp"

ADTStack::ADTStack() : Object() {
	size = 0;
}

ADTStack::~ADTStack() {

}

bool ADTStack::isEmpty() const {
	return size == 0;
}