#include "ADTQueue.hpp"

ADTQueue::ADTQueue() : Object() {
	size = 0;
}

ADTQueue::~ADTQueue() {

}

bool ADTQueue::isEmpty() const {
	return size == 0;
}