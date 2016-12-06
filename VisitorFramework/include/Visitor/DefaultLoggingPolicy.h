/*
 * DefaultLoggingPolicy.h
 *
 *  Created on: 22.05.2016
 *      Author: Gerd
 */

#ifndef DEFAULTLOGGINGPOLICY_H_
#define DEFAULTLOGGINGPOLICY_H_

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
struct DemoLoggingPolicy{
	template<class Visitable, class Visitor>
	static void logNotAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("DemoLoggingPolicy ");
		message += visitable.toString();
		message += " did not accept ";
		message += visitor.toString();
		std::cout << message << std::endl;
	}
	template<class Visitable, class Visitor>
	static void logNotVisited(Visitable const& visitable, Visitor const& visitor){
		std::string message("DemoLoggingPolicy ");
		message += visitor.toString();
		message += " did not visit ";
		message += visitable.toString();
		std::cout << message << std::endl;
	}
	template<class Visitable, class Visitor>
	static void logAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("DemoLoggingPolicy ");
		message += visitable.toString();
		message += " accepted ";
		message += visitor.toString();
		std::cout << message << std::endl;
	}
};
struct AdapterLoggingPolicy{
	template<class Visitable, class Visitor>
	static void logNotAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("AdapterLoggingPolicy ");
		message += visitable.toString();
		message += " did not accept ";
		message += visitor.toString();
		std::cout << message << std::endl;
//		std::clog << message << std::endl;
	}
	template<class Visitable, class Visitor>
	static void logNotVisited(Visitable const& visitable, Visitor const& visitor){
		std::string message("AdapterLoggingPolicy ");
		message += visitor.toString();
		message += " did not visit ";
		message += visitable.toString();
		std::cout << message << std::endl;
	}
	template<class Visitable, class Visitor>
	static void logAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("AdapterLoggingPolicy ");
		message += visitable.toString();
		message += " accepted ";
		message += visitor.toString();
		std::cout << message << std::endl;
	}
};
struct ElementLoggingPolicy{
	template<class Visitable, class Visitor>
	static void logNotAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("ElementLoggingPolicy ");
		message += visitable.toString();
		message += " did not accept ";
		message += visitor.toString();
		std::cout << message << std::endl;
//		std::clog << message << std::endl;
	}
	template<class Visitable, class Visitor>
	static void logAccepted(Visitable const& visitable, Visitor const& visitor){
		std::string message("ElementLoggingPolicy ");
		message += visitable.toString();
		message += " accepted ";
		message += visitor.toString();
		std::cout << message << std::endl;
	}
};

} // end namespace VisitorFramework

#ifndef LOGGING_POLICY
using DefaultLoggingPolicy = VisitorFramework::EmptyLoggingPolicy;
#else
using DefaultLoggingPolicy = LOGGING_POLICY;
//using DefaultLoggingPolicy = Visitor::DemoLoggingPolicy;
#endif

#endif /* DEFAULTLOGGINGPOLICY_H_ */
