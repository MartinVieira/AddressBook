#include <Wt/WIntValidator>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WServer>
#include <Wt/WException>
#include <Wt/WLogger>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <fstream>

using namespace std;
using namespace Wt;

class Name { //class for creating a name for a person object
	string fName, lName;
	
	public:
		Name() { //constructor to initialize a name object with no first or last name
			fName="";
			lName="";
		}

		Name(string fName, string lName) { //constructor method that accepts two strings: first and last name
			fName = fName;
			lName = lName;
		}

		string getFirst() { //getter and setter methods for name object
			return fName;}
		string getLast() {
			return lName;}
		void setFirst(string fName) {
			fName=fName;}
		void setLast(string lName) {
			lName=lName;}			
};

class Address { //class for creating an address for a person object
	string street, city, province, country;

	public:
		Address() { //constructor that initializes an address object with no street, city, province 
			street="";
			city="";
			province="";
			country="Canada";
		}
		
		Address(string street,string city,string province,string country) { //constructor that accepts four string values
			street=street;
			city=city;
			province=province;
			country=country;
		}

		string getStreet() { //getter and setter methods for an address object
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

class Phone { //class for creating a phone for a person object
	string phone;
	
	public:
		Phone() { //constructor to initialize an empty phone number
			phone="";
		}
		
		Phone(string phone) { //constructor that accepts one string
			phone=phone;
		}

		string getPhone() { //getter and setter methods for a phone object
			return phone;}
		void setPhone(string phone) {
			phone=phone;}
};

class Randomizer { //Randomizer class that generates a random name, address and phone number
	public:
		string randName() { //method to pick a random first and last name and store in name object
			Name newName;
			string first, last;
			string firstName[10] = {"Jake", "James", "Martin","Jeff", "Nick", "Dan", "Matt", "Adam", "Eve", "Sam"};
			string lastName[10] = {"Jake", "James", "Martin","Jeff", "Nick", "Dan", "Matt", "Adam", "Eve", "Sam"};
			first = firstName[rand()%10];
			last = lastName[rand()%10];
			Name(first,last);
			return first +" "+ last;
		}
		
		string randAddress() { //method to pick a random street, city, province and store in an address object
			Address newAddress;
			string nStreet, nCity, nProvince;
			string street[10] = {"123 Fake Street", "234 Real Street", "253 Top Street", "903 Bottom Street", "590 Side Street", "121 High Street", "768 Low Street", "737 Plain Street", "934 Great Street", "916 Awesome Street"};
			string city[10] = {"Toronto", "Vancouver", "Calgary", "Montreal", "Ottawa", "Edmonton", "Winnipeg", "Victoria", "Quebec City", "Hamilton"};
			string province[10] = {"Ontario", "BC", "Quebec", "Alberta", "Nova Scotia", "Newfoundland and Labrador", "Saskatchewan", "Manitoba", "New Brunswick", "PEI"};
			string country = "Canada";
			nStreet = street[rand()%10];
			nCity = city[rand()%10];
			nProvince = province[rand()%10];
			Address(nStreet,nCity,nProvince,country);
			return nStreet + " " +nCity+" "+nProvince+" "+country;
		}
		
		string randPhone() { //method to generate random phone number and store in a phone object
			Phone newPhone;
			int a = (rand()%1000+1000);
			int b = (rand()%100+100);
			int c = (rand()%100+100);
			stringstream ss, dd, ff;
			ff << c;
			dd << b;
			ss << a;
			string ftr = ff.str();
			string dtr = dd.str();
			string str = ss.str();
			string phoneNumber = dtr +"-"+ ftr +"-" + str;
			Phone().setPhone(phoneNumber);
			return phoneNumber;
		}
};

class Person { //class to generate a person object with a name, address and phone number
	string name, address, phone;

	public:
		Person() { //constructor class to initialize a person with no name, address or phone number
			name="";
			address="";
			phone="";
		}

		Person(string name,string address,string phone) { //contructor that accepts 3 strings for a person object
			name = name;
			address = address;
			phone = phone;
		}

		string getName() { //getter and setter methods for a person object
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
		string fillBook(int n) //method to fill the address book with person objects
		{
			Person people[n];
			Randomizer random[n];

			for (int i=0; i<n; i++) {
			string name=random[i].randName();
			string address=random[i].randAddress();
			string phone=random[i].randPhone();
			people[i].setName(name);
			people[i].setAddress(address);
			people[i].setPhone(phone);
			return name + " " + address + " " + phone + "\n";
			}
		}
};

class AddressApplication : public WApplication
{
	public:
		AddressApplication(const WEnvironment& env, const string& title);
	private:
		WIntValidator *validator_;
		WLineEdit *numRecord_;
		WText *listing_;

		void listPeople();
};

AddressApplication::AddressApplication(const WEnvironment& env, const string & title): WApplication(env)
{
	setTitle("Address Book"); //application title
	
	root()->addWidget(new WText("Enter number of person-records to generate: ")); //text prompt that asks user for number of person records
	numRecord_ = new WLineEdit(root()); //text input
	validator_ = new WIntValidator(0, 100); //to convert to integer value
	numRecord_->setValidator(validator_);
	numRecord_->setFocus();

	WPushButton *button = new WPushButton("Generate", root()); //creates a button
	button->setMargin(5, Left);

	root()->addWidget(new WBreak()); //inserts a break
	listing_=new WText(root());
	
	button->clicked().connect(this, &AddressApplication::listPeople); //connects the button press 
	numRecord_->enterPressed().connect(boost::bind(&AddressApplication::listPeople, this));
}

void AddressApplication::listPeople() //method for converting the string to integer and output the address book
{
	Person a;
	WString temp=numRecord_->text();
	std::string input = temp.toUTF8();
	std::stringstream str(input);
	int value=0;
	str >> value;
	listing_->setText("Person records: " + a.fillBook(value)); //update the text
}

class ListApplication : public WApplication //class for the people url
{
	public:
		ListApplication(const WEnvironment& env, const string& title);
};

ListApplication::ListApplication(const WEnvironment& env, const string& title): WApplication(env)
{
	setTitle("Address book person-records"); 
	
}

WApplication *createApplication(const WEnvironment& env)
{
	return new AddressApplication(env, "first");
}

WApplication *createSecondApplication(const WEnvironment& env)
{
	return new ListApplication(env, "second");
}

int YourWRun(int argc, char *argv[], Wt::ApplicationCreator createApplication, Wt::ApplicationCreator createSecondApplication) 
{
	try {
		WServer server(argv[0], "");
		server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
		server.addEntryPoint(Wt::Application, createApplication); //create an entry point for the main application
		server.addEntryPoint(Wt::Application, createSecondApplication,"/people"); //create an entry point for the people application
			if (server.start()) {
			 int sig = WServer::waitForShutdown(argv[0]); //waits for the signal to shutdown
			 std::cerr << "Shutdown (signal = " << sig << ")" << std::endl;
			 server.stop();
			} 
		} catch(WServer::Exception& e) { //catches exceptions
		 std::cerr << e.what() << "\n";
		 return 1;
		} catch(exception& e) {
		 std::cerr << "exception: " << e.what() << "\n";
		 return 1;
		}
}

int main(int argc, char **argv)
{
	return YourWRun(argc, argv, &createApplication, &createSecondApplication); //The last argument to WRun specifies the function that will instantiate new application objects
}
