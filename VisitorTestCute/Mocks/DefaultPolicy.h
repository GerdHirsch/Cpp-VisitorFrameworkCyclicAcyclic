/*
 * DefaultPolicy.h
 *
 *  Created on: 09.01.2017
 *      Author: Gerd
 */

#ifndef MOCKS_DEFAULTPOLICY_H_
#define MOCKS_DEFAULTPOLICY_H_

#include <iostream>

namespace VisitorTestMock{

struct MockLoggingPolicy{
	MockLoggingPolicy(){
//		if(trace) std::cout << "MockLoggingPolicy()" << std::endl;
		notAccepted = false;
		accepted = false;
		notVisited = false;
		invalidVisitable = false;
	}
	static bool notAccepted;
	static bool accepted;
	static bool notVisited;
	static bool invalidVisitable;
	static bool trace;

	static void reset(){
		notAccepted = false;
		accepted = false;
		notVisited = false;
		invalidVisitable = false;
	}

	template<class Visitable, class Visitor>
	void logNotAccepted(Visitable const& visitable, Visitor const& visitor){
		notAccepted = true;
		if(trace)
			std::cout
				<< "logNotAccepted( "
				<< visitable.toString() << ", "
				<< visitor.toString() << ")"
				<< std::endl;
	}
	template<class Visitable, class Visitor>
	void logAccepted(Visitable const& visitable, Visitor const& visitor){
		accepted = true;
		if(trace) std::cout << "logAccepted( " << visitable.toString() << ", " << visitor.toString() << ")" << std::endl;
	}
	template<class Visitable, class Visitor>
	void logNotVisited(Visitable & visitable, Visitor const& visitor){
		notVisited = true;
		visitable.defaultVisited();
		if(trace) std::cout << "logNotVisited( " << visitable.toString() << ", " << visitor.toString() << ")" << std::endl;
	}
	template<class Visitable, class Visitor>
	void logInvalidVisitable(Visitable const& visitable, Visitor const& visitor){
		invalidVisitable = true;
		if(trace) std::cout << "logInvalidVisitable( " << visitable.toString() << ", " << visitor.toString() << ")" << std::endl;
	}
};

}

#endif /* MOCKS_DEFAULTPOLICY_H_ */
