#include <string>
#include <list>
#include <iostream>
#include "person.H"
#include "addressBook.H"
#include "address.H"
#include "phone.H"
#include "name.H"
#include "random.C"

using namespace std;

addressBook *book;

addressBook::addressBook() {
	entries = 0;
}

void addressBook::fillUp() {
	for (int i=0; i <entries; i++) {
		person p; 
		p(p.getName(),p.getAddress(),p.getPhone());
		p.push_back(person(name, address, phone));
	}
}

int main() {
	int entries=0;

	cout << "Enter number of records to generate in the address book: ";
	cin >> entries;

	cout << "/n";
	cout << book;
}
