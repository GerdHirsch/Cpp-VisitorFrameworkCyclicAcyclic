/*
 * VisitableFactoryTest.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_VISITABLEFACTORYTEST_H_
#define INCLUDE_VISITABLEFACTORYTEST_H_

#include "../Mocks/VisitableFactory.h"

class VisitableFactoryTest{
	using this_type = VisitableFactoryTest;

	void makeCyclicVisitableByReference();
	void makeCyclicVisitableByValue();
	void makeCyclicVisitableByWeakpointer();

	void makeAcyclicVisitableByReference();
	void makeAcyclicVisitableByValue();
	void makeAcyclicVisitableByWeakpointer();

public:

	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeCyclicVisitableByReference));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeCyclicVisitableByValue));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeCyclicVisitableByWeakpointer));

		s.push_back(CUTE_SMEMFUN(DerivedTest, makeAcyclicVisitableByReference));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeAcyclicVisitableByValue));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeAcyclicVisitableByWeakpointer));

		return s;
	}
};

inline
void VisitableFactoryTest::makeCyclicVisitableByValue(){
	using namespace VisitorTestMock;

	auto visitable = CyclicFactory::makeVisitable(NonVisitable());

	using Visitor = MockVisitor<CR::Repository, CR::E1, NonVisitable>;
	Visitor visitor;

	visitable->accept(visitor);

	ASSERTM("Cyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeAcyclicVisitableByValue(){
	using namespace VisitorTestMock;

	auto visitable = AcyclicFactory::makeVisitable(NonVisitable());

	using Visitor = MockVisitor<AR::Repository, AR::E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Acyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeCyclicVisitableByWeakpointer(){
	using namespace VisitorTestMock;

	auto pNonVisitable = std::make_shared<NonVisitable>();
	auto visitable = CyclicFactory::makeVisitable(pNonVisitable);

	using Visitor = MockVisitor<CR::Repository, CR::E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Cyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeAcyclicVisitableByWeakpointer(){
	using namespace VisitorTestMock;

	auto pNonVisitable = std::make_shared<NonVisitable>();
	auto visitable = AcyclicFactory::makeVisitable(pNonVisitable);

	using Visitor = MockVisitor<AR::Repository, AR::E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Acyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeCyclicVisitableByReference(){
	using namespace VisitorTestMock;

	NonVisitable nonVisitable;
	auto visitable = CyclicFactory::makeVisitable(nonVisitable);

	using Visitor = MockVisitor<CR::Repository, CR::E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Cyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeAcyclicVisitableByReference(){
	using namespace VisitorTestMock;

	NonVisitable nonVisitable;
	auto visitable = AcyclicFactory::makeVisitable(nonVisitable);

	using Visitor = MockVisitor<AR::Repository, AR::E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Acyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

#endif /* INCLUDE_VISITABLEFACTORYTEST_H_ */
