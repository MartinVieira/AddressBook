#include <iostream>
#include <Wt/Http/Response>
#include "MyResource.h"

using namespace std;
using namespace Wt::Http;

MyResource::MyResouce() {
}

MyResource::~MyResource() {
}

void MyResource::handleRequest(const Request& request, Response& response)
{
	string method = request.method();
	string contentType = request.contentType();
	int contentLength = request.contentLength();
	char* buffer = new charcontentLength+1];
	request.in().read(buffer, contentLength);
	buffer[contentLength]=0;
	response.setMimeType("application/xml");
	ostream& out = response.out();
	out << "<?xml version='1.0' encoding='utf-8' ?>" << endl;
	out << "<reply>" << endl;
	out << "<method>" << method << "</method>" << endl;
	out << "<contentType>" << contentType << "</contentType>" << endl;
	out << "<contentLength>" << contentLength << "</contentLength>" << endl;
	out << "<body>" << buffer << "/body>" << endl;
	out << "</reply>";
	delete[] buffer;
}
