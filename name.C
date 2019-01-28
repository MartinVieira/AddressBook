#include <string>
#include "name.H"

using namespace std;

name::name() {
	firstName = "";
	lastName = "";
}

name::name(string firstName, string lastName) {
	firstName = firstName;
	lastName = lastName;
}

string name::getFirstName() {
	return firstName;
}

string name::getLastName() {
	return lastName;
}

void name::setfirstName(string firstName) {
	firstName = firstName;
}

void name::setLastName(string lastName) {
	lastName = lastName;
}
