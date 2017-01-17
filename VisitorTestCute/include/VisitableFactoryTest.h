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
	void makeCyclicVisitableByUniquepointer();

	void makeAcyclicVisitableByReference();
	void makeAcyclicVisitableByValue();
	void makeAcyclicVisitableByWeakpointer();
	void makeAcyclicVisitableByUniquepointer();

public:

	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeCyclicVisitableByReference));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeCyclicVisitableByValue));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeCyclicVisitableByWeakpointer));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeCyclicVisitableByUniquepointer));

		s.push_back(CUTE_SMEMFUN(DerivedTest, makeAcyclicVisitableByReference));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeAcyclicVisitableByValue));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeAcyclicVisitableByWeakpointer));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeAcyclicVisitableByUniquepointer));

		return s;
	}
};

inline
void VisitableFactoryTest::makeCyclicVisitableByValue(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	auto visitable = Factory::makeVisitable(NonVisitable());

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;

	visitable->accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeAcyclicVisitableByValue(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	auto visitable = Factory::makeVisitable(NonVisitable());

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Acyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeCyclicVisitableByWeakpointer(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	auto pNonVisitable = std::make_shared<NonVisitable>();
	auto visitable = Factory::makeVisitable(pNonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Cyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeCyclicVisitableByUniquepointer(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	auto visitable = Factory::makeVisitable(std::make_unique<NonVisitable>());

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeAcyclicVisitableByUniquepointer(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	auto visitable = Factory::makeVisitable(std::make_unique<NonVisitable>());

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeAcyclicVisitableByWeakpointer(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	auto pNonVisitable = std::make_shared<NonVisitable>();
	auto visitable = Factory::makeVisitable(pNonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeCyclicVisitableByReference(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	NonVisitable nonVisitable;
	auto visitable = Factory::makeVisitable(nonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Cyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

inline
void VisitableFactoryTest::makeAcyclicVisitableByReference(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	NonVisitable nonVisitable;
	auto visitable = Factory::makeVisitable(nonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	visitable->accept(visitor);

	ASSERTM("Acyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}

#endif /* INCLUDE_VISITABLEFACTORYTEST_H_ */
