#include <iostream>
#include <random>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Person {
	string name, address, phone;

	public:
		Person() {
			name="";
			address="";
			phone="";
		}

		Person(string name,string address,string phone) {
			name = name;
			address = address;
			phone = phone;
		}

		string getName() {
			return name;}
		string getAddress() {
			return address;}
		string getPhone() {
			return phone;}
		void setName(string name) {
			name=name;}
		void setAddress(string address) {
			address=address;}
		void setPhone(string phone) {
			phone=phone;}
};	

class Name {
	string fName, lName;
	
	public:
		Name() {
			fName="";
			lName="";
		}

		Name(string fName, string lName) {
			fName = fName;
			lName = lName;
		}

		string getFirst() {
			return fName;}
		string getLast() {
			return lName;}
		void setFirst(string fName) {
			fName=fName;}
		void setLast(string lName) {
			lName=lName;}			
};

class Address {
	string street, city, province, country;

	public:
		Address() {
			street="";
			city="";
			province="";
			country="Canada";
		}
		
		Address(string street,string city,string province,string country) {
			street=street;
			city=city;
			province=province;
			country=country;
		}

		string getStreet() {
			return street;}
		string getCity() {
			return city;}
		string getProvince() {
			return province;}
		string getCountry() {
			return country;}
		void setStreet(string street) {
			street=street;}
		void setCity(string city) {
			city=city;}
		void setProvince(string province) {
			province=province;}
		void setCountry(string country) {
			country=country;}
};

class Phone {
	string phone;
	
	public:
		Phone() {
			phone="";
		}
		
		Phone(string phone) {
			phone=phone;
		}

		string getPhone() {
			return phone;}
		void setPhone(string phone) {
			phone=phone;}
};

class Randomizer {
	public:
		string randName() {
			Name newName;
			string first, last;
			string firstName[2] = {"Jake", "James"};
			string lastName[2] = {"Jake", "James"};
			first = firstName[rand()%2];
			last = lastName[rand()%2];
			Name(first,last);
			return first +" "+ last;
		}
		
		string randAddress() {
			Address newAddress;
			string nStreet, nCity, nProvince;
			string street[2] = {"1", "2"};
			string city[2] = {"1", "2"};
			string province[2] = {"1", "2"};
			string country = "Canada";
			nStreet = street[rand()%2];
			nCity = city[rand()%2];
			nProvince = province[rand()%2];
			Address(nStreet,nCity,nProvince,country);
			return nStreet + " " +nCity+" "+nProvince+" "+country;
		}
		
		string randPhone() {
			Phone newPhone;
			string phoneNum = "222-333-" + (100 + rand()%100);
			return phoneNum;
		}
};

int main() {
	int records=0;
	cout << "Enter number of person-records to be generated: ";
	cin >> records;
	Person people[records];
	Randomizer random[records];

	for (int i=0; i<records; i++) {
		string name=random[i].randName();
		string address=random[i].randAddress();
		string phone=random[i].randPhone();
		people[i].setName(name);
		people[i].setAddress(address);
		people[i].setPhone(phone);
	}
}


