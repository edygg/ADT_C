#include "SLNode.hpp"

SLNode::SLNode(Object* d) {
	data = d;
	next = NULL;
}

SLNode::~SLNode() {
	if (data)
		delete data;
	if (next)
		delete next;
}

void SLNode::setData(Object* d) {
	data = d;
}

Object* SLNode::getData() const {
	return data;
}

void SLNode::setNext(SLNode* n) {
	next = n;
}

SLNode* SLNode::getNext() const {
	return next;
}