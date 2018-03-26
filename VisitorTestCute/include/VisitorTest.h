/*
 * VisitorCyclicTest.h
 *
 *  Created on: 02.12.2016
 *      Author: Gerd
 */

#ifndef INCLUDE_VISITORTEST_H_
#define INCLUDE_VISITORTEST_H_

#include "../Mocks/DefaultPolicy.h"

#include "../Mocks/MockVisitor.h"

#include "../Mocks/CyclicVisitables.h"
#include "../Mocks/AcyclicVisitables.h"

#include "../Mocks/CyclicRepository.h"
#include "../Mocks/AcyclicRepository.h"

#include "../Mocks/NonVisitableWithAccessor.h"
#include "../Mocks/CyclicVisitableWithAccessor.h"
#include "../Mocks/AcyclicVisitableWithAccessor.h"

#include <iostream>

class VisitorTest{
public:
	VisitorTest(){
		VisitorTestMock::MockLoggingPolicy::trace = false;
	}
	using this_type = VisitorTest;

	template<class Visitor, class Visitable>
	bool visitVisitablesImpl();

	//=====================================
	// Cyclic
	//=====================================
	void visitCyclic();
	// Default Policies
	void visitCyclicLogAccepted();
	void visitCyclicLogNotVisited();
	//=====================================
	// Acyclic
	//=====================================
	void visitAcyclic();
	// Default Policies
	void visitAcyclicLogAccepted();
	void visitAcyclicLogNotAccepted();
	void visitAcyclicLogNotVisited();

	//=====================================
	// Accessor
	//=====================================
	void visitCyclicVisitableWithAccessor();
	void visitCyclicNonVisitableWithAccessor();
	void visitAcyclicVisitableWithAccessor();
	void visitAcyclicNonVisitableWithAccessor();
	void visitCyclicNonVisitableAmbiguousAccessorMethod(); //
	void visitCyclicVisitableAmbiguousAccessorMethod(); //
	void visitAcyclicAmbiguousAccessorMethod(); //

	void visitMixedVisitables(); // A, B, NonVisitable
	void visitPartitionOfVisitables(); // A, B not C


	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		//=====================================
		// Cyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclic));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicLogAccepted));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicLogNotVisited));

		//=====================================
		// Acyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclic));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicLogAccepted));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicLogNotAccepted));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicLogNotVisited));

		//=====================================
		// Accessor
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicVisitableWithAccessor));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicNonVisitableWithAccessor));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicNonVisitableAmbiguousAccessorMethod));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicVisitableAmbiguousAccessorMethod));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicVisitableWithAccessor));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicNonVisitableWithAccessor));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicAmbiguousAccessorMethod));

		return s;
	}
};

inline
void VisitorTest::visitCyclicVisitableWithAccessor(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitable = VisitableWithAccessor;
	using Visitor = MockVisitorUseAccessor<AccessorRepository, Visitable>;
	Visitable visitable;
	Visitor visitor;

	visitable.accept(visitor);
	bool result = visitor.accessedValue;

	std::string message("Visitor::visit(NonVisitableWithAccessor&) accessedValue not changed");
	ASSERTM(message, result);
}
inline
void VisitorTest::visitCyclicNonVisitableWithAccessor(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitable = NonVisitableWithAccessor;
	using Visitor = MockVisitorUseAccessor<AccessorRepository, Visitable>;
	Visitable visitable;
	AccessorRepository::AdapterByReference<Visitable> adapter(visitable);

	Visitor visitor;
	adapter.accept(visitor);

	bool result = visitor.accessedValue;

	std::string message("Visitor::visit(NonVisitableWithAccessor&) accessedValue not changed");
	ASSERTM(message, result);
}
inline
void VisitorTest::visitCyclicVisitableAmbiguousAccessorMethod(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitable = VisitableWithAccessor2;
	using Visitor = MockVisitorUseAccessor<AccessorRepository, Visitable>;
	Visitable visitable;
	Visitor visitor;

	visitable.accept(visitor);
	bool result = visitor.accessedValue;

	std::string message("Visitor::visit(VisitableWithAccessor2&) accessedValue not changed");
	ASSERTM(message, result);
}
inline
void VisitorTest::visitCyclicNonVisitableAmbiguousAccessorMethod(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitable = NonVisitableWithAccessor2;
	using Visitor = MockVisitorUseAccessor<AccessorRepository, Visitable>;
	Visitable nvwA;
	AccessorRepository::AdapterByReference<Visitable> adapter(nvwA);

	Visitor visitor;
	adapter.accept(visitor);

	bool result = visitor.accessedValue;
	std::string message("Visitor::visit(NonVisitableWithAccessor2&) accessedValue not changed");
	ASSERTM(message, result);
}
inline
void VisitorTest::visitAcyclicVisitableWithAccessor(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitable = VisitableWithAccessor;
	using Visitor = MockVisitorUseAccessor<AccessorRepository, Visitable>;
	Visitable visitable;
	Visitor visitor;

	visitable.accept(visitor);
	bool result = visitor.accessedValue;

	std::string message("Visitor::visit(VisitableWithAccessor&) accessedValue not changed");
	ASSERTM(message, result);
//	ASSERTM("implement test", false);
}
inline
void VisitorTest::visitAcyclicNonVisitableWithAccessor(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitable = NonVisitableWithAccessor;
	using Visitor = MockVisitorUseAccessor<AccessorRepository, Visitable>;
	Visitable nvwA;
	AccessorRepository::AdapterByReference<Visitable> adapter(nvwA);

	Visitor visitor;
	adapter.accept(visitor);

	bool result = visitor.accessedValue;
	std::string message("Visitor::visit(NonVisitableWithAccessor&) accessedValue not changed");
	ASSERTM(message, result);
}
inline
void VisitorTest::visitAcyclicAmbiguousAccessorMethod(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitable = NonVisitableWithAccessor2;
	using Visitor = MockVisitorUseAccessor<AccessorRepository, Visitable>;
	Visitable nvwA;
	AccessorRepository::AdapterByReference<Visitable> adapter(nvwA);

	Visitor visitor;
	adapter.accept(visitor);

	bool result = visitor.accessedValue;
	std::string message("Visitor::visit(NonVisitableWithAccessor2&) accessedValue not changed");
	ASSERTM(message, result);
}
////=====================================
//// Cyclic
////=====================================
inline
void VisitorTest::visitCyclic(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	bool result = false;
	using Visitor = MockVisitor<Repository, E1>;
	result = visitVisitablesImpl<Visitor, E1>();
	ASSERTM("Cyclic Visitor::visit(E1&) not called", result);
}
inline
void VisitorTest::visitCyclicLogAccepted(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitor<Repository, E1>;
	visitVisitablesImpl<Visitor, E1>();
	ASSERTM("DefaultPolicy logAccepted not called", MockLoggingPolicy::accepted);
}
inline
void VisitorTest::visitCyclicLogNotVisited(){
	using namespace CyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitor<Repository, E3>;
	visitVisitablesImpl<Visitor, E2>();
	ASSERTM("DefaultPolicy logNotVisited not called", MockLoggingPolicy::notVisited);
}
//=====================================
// Acyclic
//=====================================
inline
void VisitorTest::visitAcyclic(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	bool result = false;
	using Visitor = MockVisitor<Repository, E1, E2>;

	result = visitVisitablesImpl<Visitor, E1>();
	ASSERTM("Acyclic Visitor::visit(E1&) not called", result);

	ASSERTM("DefaultPolicy logNotVisited called", !MockLoggingPolicy::notVisited);
}
inline
void VisitorTest::visitAcyclicLogAccepted(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitor<Repository, E1, E2>;
	visitVisitablesImpl<Visitor, E1>();
	ASSERTM("DefaultPolicy logAccepted not called", MockLoggingPolicy::accepted);
}
inline
void VisitorTest::visitAcyclicLogNotAccepted(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitor<Repository, E1>;
	visitVisitablesImpl<Visitor, E2>();
	ASSERTM("DefaultPolicy logNotAccepted not called", MockLoggingPolicy::notAccepted);
}
inline
void VisitorTest::visitAcyclicLogNotVisited(){
	using namespace AcyclicRepository;
	using namespace VisitorTestMock;

	using Visitor = MockVisitor<Repository, E1, E2>;
	visitVisitablesImpl<Visitor, E2>();
	ASSERTM("DefaultPolicy logNotVisited not called", MockLoggingPolicy::notVisited);
}
//=====================================
template<class Visitor, class Visitable>
inline
bool VisitorTest::visitVisitablesImpl(){
	std::cout << "Visitable visitable;" << std::endl;
	Visitable visitable;
	std::cout << "Visitor visitor;" << std::endl;
	Visitor visitor;
	visitable.accept(visitor);

//	ASSERTM("Visitor::visit(Visitable&) not called", visitor.visitableVisited);
	return visitor.visitableVisited;
}

#endif /* INCLUDE_VISITORTEST_H_ */
