#ifndef MYRESOURCE_H_
#define MYRESOURCE_H_
	
#include <Wt/WResource>

using namespace Wt;
using namespace Wt::Http;

class MyResource:public WResource
{
	public:
		MyResource();
		virtual ~MyResource();
	protected:
		virtual void handleRequest(const Request &request, Response &response);
};

#endif
