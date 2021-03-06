#include "log.h"
#include <iostream>

void info(WLogger& logger, const string& message) 
{
	WLOgEntry entry = logger.entry("info");
	entry << WLogger::timestamp << WLogger::sep << WLogger::sep << '[' << "info" << ']' << 		WLogger::sep << message;
}

void fatal(WLogger& logger, const string& message, const char* what) 
{
	WLOgEntry entry = logger.entry("fatal");
	entry << WLogger::timestamp << WLogger::sep << WLogger::sep << '[' << "fatal" << ']' << 	WLogger::sep << message << what;
}

void fatal(WLogger& logger, const string& message)
{
 fatal(logger, message, "");
}

void configLogger(WLogger& logger) 
{
	logger.addField("datetime", false);
	logger.addField("type", false);
	logger.addField("message", true);
	logger.setFile("/var/log/resource.log");
}
