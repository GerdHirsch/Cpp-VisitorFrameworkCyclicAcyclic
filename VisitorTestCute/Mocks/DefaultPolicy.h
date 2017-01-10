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
		std::cout << "MockLoggingPolicy()" << std::endl;
		notAccepted = false;
		accepted = false;
		notVisited = false;
		invalidVisitable = false;
	}
	static bool notAccepted;
	static bool accepted;
	static bool notVisited;
	static bool invalidVisitable;

	template<class Visitable, class Visitor>
	static void logNotAccepted(Visitable const& visitable, Visitor const& visitor){
		notAccepted = true;
	}
	template<class Visitable, class Visitor>
	static void logAccepted(Visitable const& visitable, Visitor const& visitor){
		accepted = true;
	}
	template<class Visitable, class Visitor>
	static void logNotVisited(Visitable const& visitable, Visitor const& visitor){
		notVisited = true;
	}
	template<class Visitable, class Visitor>
	static void logInvalidVisitable(Visitable const& visitable, Visitor const& visitor){
		invalidVisitable = true;
	}
};

}

#endif /* MOCKS_DEFAULTPOLICY_H_ */
