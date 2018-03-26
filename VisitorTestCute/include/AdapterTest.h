/*
 * AdapterTest.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_ADAPTERTEST_H_
#define INCLUDE_ADAPTERTEST_H_


#include "../Mocks/DefaultPolicy.h"

#include "../Mocks/MockVisitor.h"

#include "../Mocks/CyclicVisitables.h"
#include "../Mocks/AcyclicVisitables.h"

#include "../Mocks/CyclicRepository.h"
#include "../Mocks/AcyclicRepository.h"

#include "../Mocks/NonVisitable.h"

#include <memory>
#include <iostream>

class AdapterTest{
	using this_type = AdapterTest;

	// TODO how to test this property?
	void notConstructibleWithRValueSharedPtr();
	//=====================================
	// Cyclic
	//=====================================
	void visitCyclicAdapterByReference();
	void visitCyclicAdapterByValue();

	void visitCyclicAdapterByWeakpointer();
	void visitCyclicAdapterInvalidVisitable();
	void cyclicAdapterWeakpointerStayValid();
	//=====================================
	// Acyclic
	//=====================================
	void visitAcyclicAdapterByReference();
	void visitAcyclicAdapterByValue();

	void visitAcyclicAdapterByWeakpointer();
	void visitAcyclicAdapterInvalidVisitable();
	void acyclicAdapterWeakpointerStayValid();

public:
	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		//=====================================
		// Cyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicAdapterByReference));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicAdapterByValue));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicAdapterByWeakpointer));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitCyclicAdapterInvalidVisitable));
		s.push_back(CUTE_SMEMFUN(DerivedTest, cyclicAdapterWeakpointerStayValid));
		//=====================================
		// Acyclic
		//=====================================
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicAdapterByReference));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicAdapterByValue));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicAdapterByWeakpointer));
		s.push_back(CUTE_SMEMFUN(DerivedTest, visitAcyclicAdapterInvalidVisitable));
		s.push_back(CUTE_SMEMFUN(DerivedTest, acyclicAdapterWeakpointerStayValid));

		return s;
	}
};

//=====================================
// Cyclic
//=====================================
inline
void AdapterTest::visitCyclicAdapterByReference(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	NonVisitable nonVisitable;
	Repository::AdapterByReference<NonVisitable> adapter(nonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	adapter.accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}
inline
void AdapterTest::visitCyclicAdapterByValue(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	NonVisitable nonVisitable;
	Repository::AdapterByValue<NonVisitable> adapter(nonVisitable);
	//temporäre objekte Adapter Ctor
	Repository::AdapterByValue<NonVisitable> adapterWithTemp((NonVisitable()) );

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	adapter.accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}
inline
void AdapterTest::visitCyclicAdapterByWeakpointer(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	auto nonVisitable = std::make_shared<NonVisitable>();
	Repository::AdapterByWeakpointer<NonVisitable> adapter(nonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	adapter.accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}
inline
void AdapterTest::visitCyclicAdapterInvalidVisitable(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	using Adapter = Repository::AdapterByWeakpointer<NonVisitable>;
	std::shared_ptr<Adapter> pAdapter;
	{
		auto nonVisitable = std::make_shared<NonVisitable>();
		pAdapter = std::make_shared<Adapter>(nonVisitable);
	}

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;

	ASSERTM("DefaultPolicy logInvalidVisitable not initialized", !MockLoggingPolicy::invalidVisitable);

	pAdapter->accept(visitor);

	ASSERTM("DefaultPolicy logInvalidVisitable not called", MockLoggingPolicy::invalidVisitable);
}
inline
void AdapterTest::cyclicAdapterWeakpointerStayValid(){
	using namespace VisitorTestMock;
	using namespace CyclicRepository;

	using Adapter = Repository::AdapterByWeakpointer<NonVisitable>;
	auto nonVisitable = std::make_shared<NonVisitable>();

	std::weak_ptr<NonVisitable> pWeak(nonVisitable);

	auto pAdapter = std::make_shared<Adapter>(pWeak);;
	auto p = pWeak.lock();

	ASSERTM("Weak_ptr not copied", p != nullptr );
}
//=====================================
// Acyclic
//=====================================
inline
void AdapterTest::visitAcyclicAdapterByReference(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	NonVisitable nonVisitable;
	Repository::AdapterByReference<NonVisitable> adapter(nonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	adapter.accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}
inline
void AdapterTest::visitAcyclicAdapterByValue(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	NonVisitable nonVisitable;
	Repository::AdapterByValue<NonVisitable> adapter(nonVisitable);
	Repository::AdapterByValue<NonVisitable> adapterTemp((NonVisitable()) );

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	adapter.accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}
inline
void AdapterTest::visitAcyclicAdapterByWeakpointer(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	auto nonVisitable = std::make_shared<NonVisitable>();
	Repository::AdapterByWeakpointer<NonVisitable> adapter(nonVisitable);

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;
	adapter.accept(visitor);

	ASSERTM("Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);
}
inline
void AdapterTest::visitAcyclicAdapterInvalidVisitable(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	using Adapter = Repository::AdapterByWeakpointer<NonVisitable>;
	std::shared_ptr<Adapter> pAdapter;
	{
		auto nonVisitable = std::make_shared<NonVisitable>();
		pAdapter = std::make_shared<Adapter>(nonVisitable);
	}

	using Visitor = MockVisitor<Repository, E1, NonVisitable>;
	Visitor visitor;

	ASSERTM("DefaultPolicy logInvalidVisitable not initialized", !MockLoggingPolicy::invalidVisitable);

	pAdapter->accept(visitor);

	ASSERTM("DefaultPolicy logInvalidVisitable not called", MockLoggingPolicy::invalidVisitable);
}
inline
void AdapterTest::acyclicAdapterWeakpointerStayValid(){
	using namespace VisitorTestMock;
	using namespace AcyclicRepository;

	using Adapter = Repository::AdapterByWeakpointer<NonVisitable>;
	auto nonVisitable = std::make_shared<NonVisitable>();

	std::weak_ptr<NonVisitable> pWeak(nonVisitable);

	auto pAdapter = std::make_shared<Adapter>(pWeak);;
	auto p = pWeak.lock();

	ASSERTM("Weak_ptr not copied", p != nullptr );
}
#endif /* INCLUDE_ADAPTERTEST_H_ */
