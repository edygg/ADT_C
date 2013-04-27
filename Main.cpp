#include "Object.hpp"
#include "DSArray.hpp"
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
	DSArray list;
	list.insert(new Nombre("a"), 0);
	list.insert(new Nombre("b"), 1);
	list.insert(new Nombre("c"), 2);
	list.insert(new Nombre("d"), 0);
	list.insert(new Nombre("e"), 1);
	list.insert(new Nombre("f"), 0);
	printList(list);
	
	list.remove(0);
	list.remove(3);
	printList(list);

	cout << list.first()->toString() << endl
		 << list.last()->toString() << endl;

	cout << list.indexOf(new Nombre("e")) << endl;	
	
	return 0;
}

void printList(ADTList& l) {
	for (int i = 0; i < l.getSize(); i++) {
		cout << setw(4) << l.get(i)->toString();
	}

	cout << endl;
}