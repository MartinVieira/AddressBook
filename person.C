#include <string>
#include "person.H"
#include "random.C"

using namespace std;

person::person() {
	name= "";
	address= "";
	phone= "";
}

string person::getName() {
	string name = random(firstName, lastName);
	return name;
}

string person::getAddress() {
	string address = random(street,city,province,country);
	return address;
}

string person::getPhone() {
	string phone = random(phoneNumber);
	return phone;
}
