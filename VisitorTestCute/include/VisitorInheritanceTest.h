/*
 * VisitorInheritanceTest.h
 *
 *  Created on: 15.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_VISITORINHERITANCETEST_H_
#define INCLUDE_VISITORINHERITANCETEST_H_

#include "../Mocks/DefaultPolicy.h"

#include "../Mocks/MockVisitor.h"

#include "../Mocks/CyclicVisitables.h"
#include "../Mocks/AcyclicVisitables.h"

#include "../Mocks/CyclicRepository.h"
#include "../Mocks/AcyclicRepository.h"

#include <iostream>

class VisitorInheritanceTest{
public:
	VisitorInheritanceTest(){
		VisitorTestMock::MockLoggingPolicy::trace = false;
	}
	using this_type = VisitorInheritanceTest;
	//=====================================
	// Cyclic
	//=====================================
	void visitCyclicDerivedBase();
	void visitCyclicBase();
	void visitCyclicDerived();
	//=====================================
	// Acyclic
	//=====================================
	void visitAcyclicDerivedBase();
	void visitAcyclicBase();
	void visitAcyclicDerived();


	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		//=====================================
		// Cyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicDerivedBase));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicBase));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicDerived));
		//=====================================
		// Acyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicDerivedBase));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicBase));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicDerived));

		return s;
	}
};
// implements visit(Derived) visit method
inline
void VisitorInheritanceTest::visitCyclicDerived(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitorInheritance<Repository, E2, NonVisitable>;
	{
		using Visitable1 = E2;
		using Visitable2 = E1;

		Visitor visitor;
		Visitable1 visitable1;
		Visitable2 visitable2;

		visitable1.accept(visitor);

		ASSERTM("Visitor::visit(Visitable1&) not called", visitor.visitableVisited1);
		ASSERTM("Default policy visited Visitable1 : ", !visitable1.wasDefaultVisited);
		ASSERTM("visitor visited Visitable1 : ", visitable1.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotVisited called", !MockLoggingPolicy::notVisited);

		MockLoggingPolicy::reset();

		visitable2.accept(visitor);

		ASSERTM("Visitable2 not Default policy visited  : ", visitable2.wasDefaultVisited);
		ASSERTM("visitor visited Visitable2 : ", !visitable2.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotVisited not called", MockLoggingPolicy::notVisited);
	}
}
// implements visit(Derived) visit method
inline
void VisitorInheritanceTest::visitCyclicBase(){

	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitorInheritance<Repository, E1, NonVisitable>;
	{
		using Visitable1 = E1;
		using Visitable2 = E2;

		Visitor visitor;
		Visitable1 visitable1;
		Visitable2 visitable2;

//		MockLoggingPolicy::trace = true;

		visitable1.accept(visitor);

		ASSERTM("Visitor::visit(Visitable1&) not called", visitor.visitableVisited1);
		ASSERTM("Default policy visited Visitable1 : ", !visitable1.wasDefaultVisited);
		ASSERTM("visitor visited not Visitable1 : ", visitable1.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotVisited called", !MockLoggingPolicy::notVisited);

		MockLoggingPolicy::reset();

		visitable2.accept(visitor);

		ASSERTM("Visitor::visit(Visitable2&) called", !visitor.visitableVisited2);

		// All visit methods must be implemented either default or special
		ASSERTM("DefaultPolicy logNotVisited not called", MockLoggingPolicy::notVisited);
		ASSERTM("Visitable2 Default policy not visited : ", visitable2.wasDefaultVisited);

		ASSERTM("visitor visited Visitable2 : ", !visitable2.wasVisitorVisited);
	}

}

// implements visit(Base) and visit(Derived) visit method
inline
void VisitorInheritanceTest::visitCyclicDerivedBase(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitorInheritance<Repository, E1, E2>;
	{
		using Visitable1 = E1;
		using Visitable2 = E2;

		Visitor visitor;
		Visitable1 visitable1;
		Visitable2 visitable2;

		visitable1.accept(visitor);

		ASSERTM("Visitor::visit(Visitable1&) not called", visitor.visitableVisited1);
		ASSERTM("Default policy visited Visitable1 : ", !visitable1.wasDefaultVisited);
		ASSERTM("visitor visited Visitable1 : ", visitable1.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted called", !VisitorTestMock::MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !VisitorTestMock::MockLoggingPolicy::notVisited);

		MockLoggingPolicy::reset();

		visitable2.accept(visitor);

		ASSERTM("Acyclic Visitor::visit(Visitable2&) not called", visitor.visitableVisited2);
		ASSERTM("Default policy visited Visitable2 : ", !visitable2.wasDefaultVisited);
		ASSERTM("visitor visited Visitable2 : ", visitable2.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted called", !VisitorTestMock::MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !VisitorTestMock::MockLoggingPolicy::notVisited);
	}
}

// implements visit(Base) and visit(Derived) visit method
inline
void VisitorInheritanceTest::visitAcyclicDerivedBase(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitorInheritance<Repository, E1, E2>;
	{
		using Visitable1 = E1;
		using Visitable2 = E2;

		Visitor visitor;
		Visitable1 visitable1;
		Visitable2 visitable2;

		visitable1.accept(visitor);

		ASSERTM("Visitor::visit(Visitable1&) not called", visitor.visitableVisited1);
		ASSERTM("Default policy visited Visitable1 : ", !visitable1.wasDefaultVisited);
		ASSERTM("visitor visited Visitable1 : ", visitable1.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted called", !VisitorTestMock::MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !VisitorTestMock::MockLoggingPolicy::notVisited);

		MockLoggingPolicy::reset();

		visitable2.accept(visitor);

		ASSERTM("Visitor::visit(Visitable2&) not called", visitor.visitableVisited2);
		ASSERTM("Default policy visited Visitable2 : ", !visitable2.wasDefaultVisited);
		ASSERTM("visitor visited Visitable2 : ", visitable2.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted called", !VisitorTestMock::MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !VisitorTestMock::MockLoggingPolicy::notVisited);
	}
}
// implements visit(Derived) visit method
inline
void VisitorInheritanceTest::visitAcyclicDerived(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitorInheritance<Repository, E2, NonVisitable>;
	{
		using Visitable1 = E2;
		using Visitable2 = E1;

		Visitor visitor;
		Visitable1 visitable1;
		Visitable2 visitable2;

		visitable1.accept(visitor);

		ASSERTM("Visitor::visit(Visitable1&) not called", visitor.visitableVisited1);
		ASSERTM("Default policy visited Visitable1 : ", !visitable1.wasDefaultVisited);
		ASSERTM("visitor visited Visitable1 : ", visitable1.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted called", !MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !MockLoggingPolicy::notVisited);

		MockLoggingPolicy::reset();

		visitable2.accept(visitor);

		ASSERTM("Default policy visited Visitable2 : ", !visitable2.wasDefaultVisited);
		ASSERTM("visitor visited Visitable2 : ", !visitable2.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted not called", MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !MockLoggingPolicy::notVisited);
	}
}

// implements visit(Base&) method
inline
void VisitorInheritanceTest::visitAcyclicBase(){

	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitorInheritance<Repository, E1, NonVisitable>;
	{
		using Visitable1 = E1;
		using Visitable2 = E2;

		Visitor visitor;
		Visitable1 visitable1;
		Visitable2 visitable2;

//		MockLoggingPolicy::trace = true;

		visitable1.accept(visitor);

		ASSERTM("Visitor::visit(Visitable1&) not called", visitor.visitableVisited1);
		ASSERTM("Default policy visited Visitable1 : ", !visitable1.wasDefaultVisited);
		ASSERTM("visitor visited not Visitable1 : ", visitable1.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted called", !MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !MockLoggingPolicy::notVisited);

		MockLoggingPolicy::reset();

		visitable2.accept(visitor);

		ASSERTM("Visitor::visit(Visitable2&) called", !visitor.visitableVisited2);
		ASSERTM("Visitable2 Default policy visited : ", !visitable2.wasDefaultVisited);
		ASSERTM("visitor visited Visitable2 : ", !visitable2.wasVisitorVisited);

		ASSERTM("DefaultPolicy logNotAccepted not called", MockLoggingPolicy::notAccepted);
		ASSERTM("DefaultPolicy logNotVisited called", !MockLoggingPolicy::notVisited);
	}
}


#endif /* INCLUDE_VISITORINHERITANCETEST_H_ */
