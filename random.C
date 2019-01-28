#include <string>
#include "random.H"
#include "name.C"
#include "address.C"
#include "phone.C"

using namespace std;

random::random(string firstName, string lastName) {
	string firstName[2] = {"Jake", "James"};
	string lastName[2] = {"Jake", "James"};
	int RandIndex = rand() % 2;
	firstName = firstName[RandIndex];
	lastName = lastName[RandIndex];
	name(firstName,lastName);
}

random::random(string street, string city, string province, string country) {
	string street[2] = {"1", "2"};
	string city[2] = {"1", "2"};
	string province[2] = {"1", "2"};
	string country = "Canada";
	int RandIndex = rand() % 2;
	street = street[RandIndex];
	city = city[RandIndex];
	province = province[RandIndex];
	address(street,city,province,country);
}

random::random(string phone) {
	string phone = "222-333-" + (100 + rand()%100);
	phone(phoneNumber)
}



