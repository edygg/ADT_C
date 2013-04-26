#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <string>
#include <sstream>

using namespace std;

class Object 
{
public:
	Object();
	virtual ~Object();
	virtual string toString() const;
	virtual bool equals(Object*) const;
};

#endif