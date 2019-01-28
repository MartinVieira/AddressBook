#include <string>
#include "phone.H"

using namespace std;

phone::phone() {
	phoneNumber="";
}

phone::phone(string phoneNumber) {
	phoneNumber = phoneNumber;
}

string phone::getPhone() {
	return phoneNumber;
}

void phone::setPhone(string phoneNumber) {
	phoneNumber = phoneNumber;
}
