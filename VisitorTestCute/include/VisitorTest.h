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

#include <iostream>

namespace CR = CyclicRepository;
namespace AR = AcyclicRepository;
namespace VTM = VisitorTestMock;

class VisitorTest{
public:
	using this_type = VisitorTest;

	template<class Visitor, class Visitable>
	bool visitVisitablesImpl();

	//=====================================
	// Cyclic
	//=====================================
	void visitCyclic();
	void visitCyclicDerivedBase();
	// Default Policies
	void visitCyclicLogAccepted();
	void visitCyclicLogNotVisited();
	void visitCyclicVisitableWithAccessor();
	void visitCyclicNonVisitableWithAccessor();
	//=====================================
	// Acyclic
	//=====================================
	void visitAcyclic();
	void visitAcyclicDerivedBase();
	// Default Policies
	void visitAcyclicLogAccepted();
	void visitAcyclicLogNotAccepted();
	void visitAcyclicLogNotVisited();
	void visitAcyclicVisitableWithAccessor();
	void visitAcyclicNonVisitableWithAccessor();

	void visitMixedVisitables(); // A, B, NonVisitable
	void visitPartitionOfVisitables(); // A, B not C
	void visitVisitableWithAccessor(); // Only AcyclicVisitor
	void visitNonVisitableWithAccessor(); // Only AcyclicVisitor

	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		//=====================================
		// Cyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclic));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicDerivedBase));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicLogAccepted));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicLogNotVisited));

		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicVisitableWithAccessor));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicNonVisitableWithAccessor));
		//=====================================
		// Acyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclic));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicDerivedBase));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicLogAccepted));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicLogNotAccepted));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicLogNotVisited));

		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicVisitableWithAccessor));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicNonVisitableWithAccessor));


		return s;
	}
};
inline
void VisitorTest::visitCyclicVisitableWithAccessor(){
	ASSERTM("Todo: implement test", false);
}
inline
void VisitorTest::visitCyclicNonVisitableWithAccessor(){
	ASSERTM("Todo: implement test", false);
}
inline
void VisitorTest::visitAcyclicVisitableWithAccessor(){
	ASSERTM("Todo: implement test", false);
}
inline
void VisitorTest::visitAcyclicNonVisitableWithAccessor(){
	ASSERTM("Todo: implement test", false);
}

inline
void VisitorTest::visitAcyclicDerivedBase(){
	ASSERTM("Todo: implement test", false);
}
inline
void VisitorTest::visitCyclicDerivedBase(){
	ASSERTM("Todo: implement test", false);
}
//=====================================
// Cyclic
//=====================================
inline
void VisitorTest::visitCyclic(){
	bool result = false;
	using CVisitor = VTM::MockVisitor<CR::Repository, CR::E1>;
	result = visitVisitablesImpl<CVisitor, CR::E1>();
	ASSERTM("Cyclic Visitor::visit(E1&) not called", result);
}
inline
void VisitorTest::visitCyclicLogAccepted(){
	using CVisitor = VTM::MockVisitor<CR::Repository, CR::E1>;
	visitVisitablesImpl<CVisitor, CR::E1>();
	ASSERTM("DefaultPolicy logAccepted not called", VTM::MockLoggingPolicy::accepted);
}
inline
void VisitorTest::visitCyclicLogNotVisited(){
	using CVisitor = VTM::MockVisitor<CR::Repository, CR::E1>;
	visitVisitablesImpl<CVisitor, CR::E2>();
	ASSERTM("DefaultPolicy logNotVisited not called", VTM::MockLoggingPolicy::notVisited);
}
//=====================================
// Acyclic
//=====================================
inline
void VisitorTest::visitAcyclic(){
	bool result = false;
	using Visitor = VTM::MockVisitor<AR::Repository, AR::E1, AR::E2>;

	result = visitVisitablesImpl<Visitor, AR::E1>();
	ASSERTM("Acyclic Visitor::visit(E1&) not called", result);

	ASSERTM("DefaultPolicy logNotVisited called", !VTM::MockLoggingPolicy::notVisited);
}
inline
void VisitorTest::visitAcyclicLogAccepted(){
	using Visitor = VTM::MockVisitor<AR::Repository, AR::E1, AR::E2>;
	visitVisitablesImpl<Visitor, AR::E1>();
	ASSERTM("DefaultPolicy logAccepted not called", VTM::MockLoggingPolicy::accepted);
}
inline
void VisitorTest::visitAcyclicLogNotAccepted(){
	using Visitor = VTM::MockVisitor<AR::Repository, AR::E1>;
	visitVisitablesImpl<Visitor, AR::E2>();
	ASSERTM("DefaultPolicy logNotAccepted not called", VTM::MockLoggingPolicy::notAccepted);
}
inline
void VisitorTest::visitAcyclicLogNotVisited(){
	using Visitor = VTM::MockVisitor<CR::Repository, CR::E1>;
	visitVisitablesImpl<Visitor, CR::E2>();
	ASSERTM("DefaultPolicy logNotVisited not called", VTM::MockLoggingPolicy::notVisited);
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
