#ifndef addressBook_H
#define addressBook_H

#include <string>
#include <list>
#include "person.H"

class addressBook {
	int entries;
	list<person> people;

	public:
		addressBook();
		void fillUp();
};

#endif
