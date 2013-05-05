#include "DLNode.hpp"

DLNode::DLNode(Object* d) : Object() {
	data = d;
	next = prev = NULL;
}

DLNode::~DLNode() {
	if (data)
		delete data;
	if(next)
		delete next;
}

void DLNode::setNext(DLNode* n) {
	next = n;
}

DLNode* DLNode::getNext() const {
	return next;
}

void DLNode::setPrev(DLNode* p) {
	prev = p;
}

DLNode* DLNode::getPrev() const {
	return prev;
}

void DLNode::setData(Object* d) {
	data = d;
}

Object* DLNode::getData() const {
	return data;
}