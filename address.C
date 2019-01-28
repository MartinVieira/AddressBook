#include <string>
#include "address.H"

using namespace std;

address::address() {
	street = "";
	city = "";
	province = "";
	country = "Canada";
}

address::address(string street, string city, string province, string country) {
	street = street;
	city = city;
	province = province;
	country = country
}

string address::getStreet() {
	return street;
}

string address::getCity() {
	return city;
}

string address::getProvince() {
	return province;
}

string address::getCountry() {
	return country;
}

void address::setStreet(string street) {
	street = street;
}

void address::setCity(string city) {
	city = city;
}

void address::setProvince(string province) {
	province = province;
}

void address::setCountry(string country) {
	country=country;
}
