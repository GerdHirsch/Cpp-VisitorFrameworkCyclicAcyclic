/*
 * MockVisitor.h
 *
 *  Created on: 09.01.2017
 *      Author: Gerd
 */

#ifndef MOCKS_MOCKVISITOR_H_
#define MOCKS_MOCKVISITOR_H_

#include <Visitor/has_method_toString.h>
//#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"
#include "CyclicVisitableWithAccessor.h"
#include "AcyclicVisitableWithAccessor.h"

class NonVisitable;

namespace VisitorTestMock{

template<class Repository, class Visitable, class ...pack>
struct MockVisitor : public Repository:: template visits<Visitable, pack...>{
public:
	bool visitableVisited = false;
	bool nonVisitableVisited = false;
	std::string toString() const override { return "MockVisitor"; }

	void visit(Visitable& v) {
//		std::cout << this->toString() << "::visit("
//				<< VisitorFramework::toString(v) << ")" << std::endl;
		visitableVisited = true;
		v.visitorVisited();
	}
	void visit(NonVisitable& v) {
//		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		nonVisitableVisited = true;
	}
};
template<class Repository, class Visitable, class ...pack>
struct MockVisitorUseAccessor : public Repository:: template visits<Visitable, pack...>{
public:
	bool visitableVisited = false;
	bool nonVisitableVisited = false;
	bool accessedValue = false;
	std::string toString() const override { return "MockVisitorUseAccessor"; }

	void visit(NonVisitableWithAccessor& v) {
//		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		nonVisitableVisited = true;
		using Accessor = NonVisitableWithAccessor::Accessor;
		this->Accessor::setData(v, true);
		accessedValue = this->Accessor::getData(v);
	}
	void visit(NonVisitableWithAccessor2& v) {
//		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		nonVisitableVisited = true;
		using Accessor = NonVisitableWithAccessor2::Accessor;
		this->Accessor::setData(v, true);
		accessedValue = this->Accessor::getData(v);
	}
	void visit(CyclicRepository::VisitableWithAccessor& v) {
//		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		nonVisitableVisited = true;
		using Accessor = CyclicRepository::VisitableWithAccessor::Accessor;
		this->Accessor::setData(v, true);
		accessedValue = this->Accessor::getData(v);
	}
	void visit(CyclicRepository::VisitableWithAccessor2& v) {
//		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		nonVisitableVisited = true;
		using Accessor = CyclicRepository::VisitableWithAccessor2::Accessor;
		this->Accessor::setData(v, true);
		accessedValue = this->Accessor::getData(v);
	}
	void visit(AcyclicRepository::VisitableWithAccessor& v) {
//		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		nonVisitableVisited = true;
		using Accessor = AcyclicRepository::VisitableWithAccessor::Accessor;
		this->Accessor::setData(v, true);
		accessedValue = this->Accessor::getData(v);
	}
	void visit(AcyclicRepository::VisitableWithAccessor2& v) {
//		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		nonVisitableVisited = true;
		using Accessor = AcyclicRepository::VisitableWithAccessor2::Accessor;
		this->Accessor::setData(v, true);
		accessedValue = this->Accessor::getData(v);
	}
};

template<class Repository, class Visitable1, class Visitable2, class ...pack>
struct MockVisitorInheritance : public Repository:: template visits<Visitable1, Visitable2, pack...>{
public:
	bool visitableVisited1 = false;
	bool visitableVisited2 = false;

	std::string toString() const override { return "MockVisitorInheritance"; }

	void visit(Visitable1& v) {
		std::cout << this->toString() << "::visit("
				<< VisitorFramework::toString(v) << ")" << std::endl;
		visitableVisited1 = true;
		v.visitorVisited();
	}
	void visit(Visitable2& v) {
		std::cout << this->toString() << "::visit("
				<< VisitorFramework::toString(v) << ")" << std::endl;
		visitableVisited2 = true;
		v.visitorVisited();
	}
};

}

#endif /* MOCKS_MOCKVISITOR_H_ */
