/*
 * DefaultLoggingPolicy.h
 *
 *  Created on: 22.05.2016
 *      Author: Gerd
 */

#ifndef DEFAULTLOGGINGPOLICY_H_
#define DEFAULTLOGGINGPOLICY_H_

#include "has_method_toString.h"

#include <string>
#include <iostream>

namespace VisitorFramework{

struct EmptyLoggingPolicy{
	template<class Visitable, class Visitor>
	static void logNotAccepted(Visitable const& visitable, Visitor const& visitor){}
	template<class Visitable, class Visitor>
	static void logNotVisited(Visitable const& visitable, Visitor const& visitor){}
	template<class Visitable, class Visitor>
	static void logAccepted(Visitable const& visitable, Visitor const& visitor){}
};
struct StdOutLoggingPolicy{
	template<class Visitable, class Visitor>
	static void logNotAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("StdOutLoggingPolicy ");
		message += VisitorFramework::toString(visitable);
		message += " did not accept ";
		message += visitor.toString();
		std::cout << message << std::endl;
	}
	template<class Visitable, class Visitor>
	static void logNotVisited(Visitable const& visitable, Visitor const& visitor){
		std::string message("StdOutLoggingPolicy ");
		message += visitor.toString();
		message += " did not visit ";
		message += VisitorFramework::toString(visitable);
		std::cout << message << std::endl;
	}
	template<class Visitable, class Visitor>
	static void logAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("StdOutLoggingPolicy ");
		message += VisitorFramework::toString(visitable);
		message += " accepted ";
		message += visitor.toString();
		std::cout << message << std::endl;
	}
};


} // end namespace VisitorFramework

#endif /* DEFAULTLOGGINGPOLICY_H_ */
