/*
 * DefaultPolicyTest.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_DEFAULTPOLICYTEST_H_
#define INCLUDE_DEFAULTPOLICYTEST_H_

#include "../Mocks/DefaultPolicy.h"

#include "../Mocks/MockVisitor.h"

#include "../Mocks/CyclicVisitables.h"
#include "../Mocks/AcyclicVisitables.h"

#include "../Mocks/CyclicRepository.h"
#include "../Mocks/AcyclicRepository.h"


#include <iostream>

class DefaultPolicyTest{

	using this_type = DefaultPolicyTest;

	void initCyclicVisitorDefaultPolicy();
	void initCyclicVisitableDefaultPolicy();
	void initAcyclicVisitorDefaultPolicy();
	void initAcyclicVisitableDefaultPolicy();
	template<class Visitor>
	void initAcyclicDefaultPolicyImpl();
	void setDefaultPolicyInitValues();

public:
//	DefaultPolicyTest(){
//		std::cout << "DefaultPolicyTest()"  << std::endl;
//	}
	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		s.push_back(CUTE_SMEMFUN(DerivedTest, initCyclicVisitorDefaultPolicy));
		s.push_back(CUTE_SMEMFUN(DerivedTest, initCyclicVisitableDefaultPolicy));
		s.push_back(CUTE_SMEMFUN(DerivedTest, initAcyclicVisitorDefaultPolicy));
		s.push_back(CUTE_SMEMFUN(DerivedTest, initAcyclicVisitableDefaultPolicy));
		return s;
	}

};
inline
void DefaultPolicyTest::initCyclicVisitorDefaultPolicy(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;
	using Visitor = MockVisitor<Repository, E1>;
	initAcyclicDefaultPolicyImpl<Visitor>();
}
inline
void DefaultPolicyTest::initCyclicVisitableDefaultPolicy(){
	using V = CR::E1;
	initAcyclicDefaultPolicyImpl<V>();
}
inline
void DefaultPolicyTest::initAcyclicVisitorDefaultPolicy(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;
	using Visitor = MockVisitor<Repository, E1>;
	initAcyclicDefaultPolicyImpl<Visitor>();
}
inline
void DefaultPolicyTest::initAcyclicVisitableDefaultPolicy(){
	using V = AR::E2;
	initAcyclicDefaultPolicyImpl<V>();
}
template<class V>
inline
void DefaultPolicyTest::initAcyclicDefaultPolicyImpl(){
	setDefaultPolicyInitValues();
	V v;
	ASSERTM("DefaultPolicy logAccepted not initialized", !VTM::MockLoggingPolicy::accepted);
	ASSERTM("DefaultPolicy logNotAccepted not initialized", !VTM::MockLoggingPolicy::accepted);
	ASSERTM("DefaultPolicy logNotVisited not initialized", !VTM::MockLoggingPolicy::notVisited);
	ASSERTM("DefaultPolicy logInvalidVisitable not initialized", !VTM::MockLoggingPolicy::invalidVisitable);
}

inline void DefaultPolicyTest::setDefaultPolicyInitValues(){
	VTM::MockLoggingPolicy::accepted = true;
	VTM::MockLoggingPolicy::notAccepted = true;
	VTM::MockLoggingPolicy::notVisited = true;
	VTM::MockLoggingPolicy::invalidVisitable = true;
}


#endif /* INCLUDE_DEFAULTPOLICYTEST_H_ */
