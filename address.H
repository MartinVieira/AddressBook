#ifndef address_H
#define address_H

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class address {
		string street;
		string city;
		string province;
		string country;

	public:
		address();
		address(string,string,string,string);

		string getStreet();
		string getCity();
		string getProvince();
		string getCountry();
		void setStreet();
		void setCity();
		void setProvince();
		void setCountry();
};

#endif
