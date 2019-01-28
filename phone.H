#ifndef phone_H
#define phone_H

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class phone {
		string phoneNumber;

	public:
		phone();
		phone(string);

		string getPhone();
		void setPhone();
};

#endif
