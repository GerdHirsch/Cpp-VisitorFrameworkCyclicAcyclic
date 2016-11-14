/*
 * DefaultLoggingPolicy.h
 *
 *  Created on: 22.05.2016
 *      Author: Gerd
 */

#ifndef DEFAULTLOGGINGPOLICY_H_
#define DEFAULTLOGGINGPOLICY_H_

/*
 * Makro LOGGING_POLICY auf die gew�nschte LoggingPolicy setzen
 * #define LOGGING_POLICY DemoLoggingPolicy
 */

struct EmptyLoggingPolicy{
	template<class Visitable, class Visitor>
	static void logNotAccepted(Visitable const& visitable, Visitor const& visitor){}
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
//		std::clog << message << std::endl;
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
#ifndef LOGGING_POLICY
using DefaultLoggingPolicy = EmptyLoggingPolicy;
#else
using DefaultLoggingPolicy = LOGGING_POLICY;
//using DefaultLoggingPolicy = DemoLoggingPolicy;
#endif

#endif /* DEFAULTLOGGINGPOLICY_H_ */