/*
 * CyclicVisitors.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef CYCLICVISITORS_H_
#define CYCLICVISITORS_H_

#include "CyclicRepository.h"

#include "CyclicVisitables.h"
#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"
#include "NonVisitableWithAccessor2.h"

namespace CyclicRepository{

class DemoVisitor13 : public Repository::VisitorBase{
public:
	void visit(E1& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E3& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	std::string toString() const override { return "DemoVisitor13"; }
};

class DemoVisitor23 : public Repository::VisitorBase{
public:
	void visit(E1& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E2& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E3& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(NonVisitable& v) {
		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
	}
	void visit(NonVisitableWithAccessor& v) {
		using Accessor = NonVisitableWithAccessor::Accessor;
		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		std::cout << this->Accessor::getData(v) << std::endl;
		Accessor::setData(v, "DemoVisitor23::Data");
//		this->AccessorsetData(v, "DemoVisitor23::Data");
		std::cout << this->Accessor::getData(v) << std::endl;
	}

	void visit(NonVisitableWithAccessor2& v) {
		using Accessor = NonVisitableWithAccessor2::Accessor;

		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		std::cout << this->Accessor::getData(v) << std::endl;
		Accessor::setData(v, "DemoVisitor23::Data");
//		this->Accessor::setData(v, "DemoVisitor23::Data");
		std::cout << this->Accessor::getData(v) << std::endl;
	}
	std::string toString() const override { return "DemoVisitor23"; }
};

} // end namespace

#endif /* CYCLICVISITORS_H_ */
