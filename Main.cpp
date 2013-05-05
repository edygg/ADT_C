#include "Object.hpp"
#include "SLQueue.hpp"
#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

class Nombre : public Object 
{
public:
	Nombre(string);
	virtual string toString() const;
	virtual bool equals(Object*) const;
private:
	string nom;
};

Nombre::Nombre(string n) {
	this->nom = n;
}

string Nombre::toString() const {
	return this->nom;
}

bool Nombre::equals(Object* other) const {
	if (typeid(*this) != typeid(*other))
		return false;
	else 
		return this->nom == dynamic_cast<Nombre*>(other)->nom;
}


void printList(ADTList&);

int main(int argc, char* argv[]) {
	/*
	DLList list;
	list.insert(new Nombre("a"), 0);
	list.insert(new Nombre("b"), 1);
	printList(list);
	list.clear();
	list.insert(new Nombre("c"), 0);
	list.insert(new Nombre("d"), 1);
	list.insert(new Nombre("e"), 2);
	list.insert(new Nombre("f"), 1);
	printList(list);
	
	list.remove(0);
	list.remove(1);
	printList(list);
	
	cout << list.first()->toString() << endl
		 << list.last()->toString() << endl;
	
	cout << list.indexOf(new Nombre("e")) << endl
	 	 << list.indexOf(new Nombre("j")) << endl;	
	*/

	/*
	SLStack stack;

	stack.push(new Nombre("E"));
	stack.push(new Nombre("A"));
	stack.push(new Nombre("S"));
	cout << setw(4) << stack.pop()->toString();
	stack.push(new Nombre("Y"));
	cout << setw(4) << stack.pop()->toString();
	stack.push(new Nombre("Q"));
	stack.push(new Nombre("U"));
	stack.push(new Nombre("E"));
	cout << setw(4) << stack.pop()->toString();
	cout << setw(4) << stack.pop()->toString();
	cout << setw(4) << stack.pop()->toString();
	stack.push(new Nombre("S"));
	stack.push(new Nombre("T"));
	cout << setw(4) << stack.pop()->toString();
	cout << setw(4) << stack.pop()->toString();
	cout << setw(4) << stack.pop()->toString();
	stack.push(new Nombre("I"));
	stack.push(new Nombre("O"));
	cout << setw(4) << stack.pop()->toString();
	stack.push(new Nombre("N"));
	cout << setw(4) << stack.pop()->toString();
	cout << setw(4) << stack.pop()->toString();
	cout << setw(4) << stack.pop()->toString();
	*/

	SLQueue queue;

	queue.queue(new Nombre("E"));
	queue.queue(new Nombre("A"));
	queue.queue(new Nombre("S"));
	cout << setw(4) << queue.dequeue()->toString();
	queue.queue(new Nombre("Y"));
	cout << setw(4) << queue.dequeue()->toString();
	queue.queue(new Nombre("Q"));
	queue.queue(new Nombre("U"));
	queue.queue(new Nombre("E"));
	cout << setw(4) << queue.dequeue()->toString();
	cout << setw(4) << queue.dequeue()->toString();
	cout << setw(4) << queue.dequeue()->toString();
	queue.queue(new Nombre("S"));
	queue.queue(new Nombre("T"));
	cout << setw(4) << queue.dequeue()->toString();
	cout << setw(4) << queue.dequeue()->toString();
	cout << setw(4) << queue.dequeue()->toString();
	queue.queue(new Nombre("I"));
	queue.queue(new Nombre("O"));
	cout << setw(4) << queue.dequeue()->toString();
	queue.queue(new Nombre("N"));
	cout << setw(4) << queue.dequeue()->toString();
	cout << setw(4) << queue.dequeue()->toString();
	cout << setw(4) << queue.dequeue()->toString();

	cout << endl;

	return 0;
}

void printList(ADTList& l) {
	for (int i = 0; i < l.getSize(); i++) {
		cout << setw(4) << l.get(i)->toString();
	}

	cout << endl;
}