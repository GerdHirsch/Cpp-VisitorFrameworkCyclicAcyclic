/*
 * VisitorAbstractTest.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_VISITORABSTRACTTEST_H_
#define INCLUDE_VISITORABSTRACTTEST_H_

#include "../Mocks/MockVisitor.h"

#include "../Mocks/CyclicVisitables.h"
#include "../Mocks/AcyclicVisitables.h"

#include "../Mocks/CyclicRepository.h"
#include "../Mocks/AcyclicRepository.h"


#include <iostream>

namespace CR = CyclicRepository;
namespace AR = AcyclicRepository;
namespace VTM = VisitorTestMock;

#include <type_traits>

class NonVisitable;
class NonVisitableWithAccessor;
class Element;

class VisitorAbstractTest{
	using this_type = VisitorAbstractTest;

	void cyclicAbstract();
	void acyclicAbstract();
public:
	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		s.push_back(CUTE_SMEMFUN(DerivedTest, cyclicAbstract));
		s.push_back(CUTE_SMEMFUN(DerivedTest, acyclicAbstract));

		return s;
	}
};
inline
void VisitorAbstractTest::cyclicAbstract(){
	using Visitor = VisitorTestMock::MockVisitor<CR::AbstractRepository, CR::typelist>;
	ASSERTM("Cyclic Visitor not abstract", std::is_abstract<Visitor>::value );
}
void VisitorAbstractTest::acyclicAbstract(){
	using Visitor = VisitorTestMock::MockVisitor<AR::AbstractRepository, AR::typelist>;
	ASSERTM("Acyclic Visitor not abstract", std::is_abstract<Visitor>::value );
}


#endif /* INCLUDE_VISITORABSTRACTTEST_H_ */
